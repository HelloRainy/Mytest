#ifndef _ASM_X86_PGTABLE_64_H
#define _ASM_X86_PGTABLE_64_H

#include <linux/const.h>
#include <asm/pgtable_64_types.h>

#ifndef __ASSEMBLY__

/*
 * This file contains the functions and defines necessary to modify and use
 * the x86-64 page table tree.
 */
#include <asm/processor.h>
#include <linux/bitops.h>
#include <linux/threads.h>

extern pud_t level3_kernel_pgt[512];
extern pud_t level3_ident_pgt[512];
extern pmd_t level2_kernel_pgt[512];
extern pmd_t level2_fixmap_pgt[512];
extern pmd_t level2_ident_pgt[512];
extern pgd_t init_level4_pgt[];

#define swapper_pg_dir init_level4_pgt

extern void paging_init(void);

#define pte_ERROR(e)					\
	pr_err("%s:%d: bad pte %p(%016lx)\n",		\
	       __FILE__, __LINE__, &(e), pte_val(e))
#define pmd_ERROR(e)					\
	pr_err("%s:%d: bad pmd %p(%016lx)\n",		\
	       __FILE__, __LINE__, &(e), pmd_val(e))
#define pud_ERROR(e)					\
	pr_err("%s:%d: bad pud %p(%016lx)\n",		\
	       __FILE__, __LINE__, &(e), pud_val(e))
#define pgd_ERROR(e)					\
	pr_err("%s:%d: bad pgd %p(%016lx)\n",		\
	       __FILE__, __LINE__, &(e), pgd_val(e))

struct mm_struct;

void set_pte_vaddr_pud(pud_t *pud_page, unsigned long vaddr, pte_t new_pte);


static inline void native_pte_clear(struct mm_struct *mm, unsigned long addr,
				    pte_t *ptep)
{
	*ptep = native_make_pte(0);
}

static inline void native_set_pte(pte_t *ptep, pte_t pte)
{
	*ptep = pte;
}

static inline void native_set_pte_atomic(pte_t *ptep, pte_t pte)
{
	native_set_pte(ptep, pte);
}

static inline void native_set_pmd(pmd_t *pmdp, pmd_t pmd)
{
	*pmdp = pmd;
}

static inline void native_pmd_clear(pmd_t *pmd)
{
	native_set_pmd(pmd, native_make_pmd(0));
}

static inline pte_t native_ptep_get_and_clear(pte_t *xp)
{
#ifdef CONFIG_SMP
	return native_make_pte(xchg(&xp->pte, 0));
#else
	/* native_local_ptep_get_and_clear,
	   but duplicated because of cyclic dependency */
	pte_t ret = *xp;
	native_pte_clear(NULL, 0, xp);
	return ret;
#endif
}

static inline pmd_t native_pmdp_get_and_clear(pmd_t *xp)
{
#ifdef CONFIG_SMP
	return native_make_pmd(xchg(&xp->pmd, 0));
#else
	/* native_local_pmdp_get_and_clear,
	   but duplicated because of cyclic dependency */
	pmd_t ret = *xp;
	native_pmd_clear(xp);
	return ret;
#endif
}

static inline void native_set_pud(pud_t *pudp, pud_t pud)
{
	*pudp = pud;
}

static inline void native_pud_clear(pud_t *pud)
{
	native_set_pud(pud, native_make_pud(0));
}

#ifdef CONFIG_PAGE_TABLE_ISOLATION
extern pgd_t kaiser_set_shadow_pgd(pgd_t *pgdp, pgd_t pgd);

static inline pgd_t *native_get_shadow_pgd(pgd_t *pgdp)
{
#ifdef CONFIG_DEBUG_VM
	/* linux/mmdebug.h may not have been included at this point */
	BUG_ON(!kaiser_enabled);
#endif
	return (pgd_t *)((unsigned long)pgdp | (unsigned long)PAGE_SIZE);
}
#else
static inline pgd_t kaiser_set_shadow_pgd(pgd_t *pgdp, pgd_t pgd)
{
	return pgd;
}
static inline pgd_t *native_get_shadow_pgd(pgd_t *pgdp)
{
	BUILD_BUG_ON(1);
	return NULL;
}
#endif /* CONFIG_PAGE_TABLE_ISOLATION */

static inline void native_set_pgd(pgd_t *pgdp, pgd_t pgd)
{
	*pgdp = kaiser_set_shadow_pgd(pgdp, pgd);
}

static inline void native_pgd_clear(pgd_t *pgd)
{
	native_set_pgd(pgd, native_make_pgd(0));
}

extern void sync_global_pgds(unsigned long start, unsigned long end);

/*
 * Conversion functions: convert a page and protection to a page entry,
 * and a page entry and page directory to the page they refer to.
 */

/*
 * Level 4 access.
 */
static inline int pgd_large(pgd_t pgd) { return 0; }
#define mk_kernel_pgd(address) __pgd((address) | _KERNPG_TABLE)

/* PUD - Level3 access */

/* PMD  - Level 2 access */
#define pte_to_pgoff(pte) ((~pte_val((pte)) & PHYSICAL_PAGE_MASK) >> PAGE_SHIFT)
#define pgoff_to_pte(off) ((pte_t) { .pte =				\
			((~(off) & (PHYSICAL_PAGE_MASK >> PAGE_SHIFT))	\
			 << PAGE_SHIFT) | _PAGE_FILE })
/*
 * Set the highest allowed nonlinear pgoff to 1 bit less than
 * x86_phys_bits to guarantee the inversion of the highest bit
 * in the pgoff_to_pte conversion. The lowest x86_phys_bits is
 * 36 so x86 implementations with 36 bits will find themselves
 * unable to keep using remap_file_pages() with file offsets
 * above 128TiB (calculated as 1<<(36-1+PAGE_SHIFT)). More
 * recent CPUs will retain much higher max file offset limits.
 */
#ifdef PTE_FILE_MAX_BITS
#error "Huh? PTE_FILE_MAX_BITS shouldn't be defined here"
#endif
#define L1TF_PTE_FILE_MAX_BITS min(__PHYSICAL_MASK_SHIFT,		\
				   boot_cpu_data.x86_phys_bits - 1)

/* PTE - Level 1 access. */

/* x86-64 always has all page tables mapped. */
#define pte_offset_map(dir, address) pte_offset_kernel((dir), (address))
#define pte_unmap(pte) ((void)(pte))/* NOP */

#if _PAGE_BIT_FILE > _PAGE_BIT_PROTNONE
#error "Unsupported PTE bit arrangement"
#endif

/*
 * Encode and de-code a swap entry
 *
 * |     ...            | 11| 10|  9|8|7|6|5| 4| 3|2|1|0| <- bit number
 * |     ...            |SW3|SW2|SW1|G|L|D|A|CD|WT|U|W|P| <- bit names
 * | TYPE (59-63) | ~OFFSET (9-58)  |0|X|X|X| X| X|X|X|0| <- swp entry
 *
 * G (8) is aliased and used as a PROT_NONE indicator for
 * !present ptes.  We need to start storing swap entries above
 * there.  We also need to avoid using A and D because of an
 * erratum where they can be incorrectly set by hardware on
 * non-present PTEs.
 *
 * The offset is inverted by a binary not operation to make the high
 * physical bits set.
 */
#define SWP_TYPE_BITS		(_PAGE_BIT_FILE - _PAGE_BIT_PRESENT - 1)
#define SWP_OFFSET_FIRST_BIT	(_PAGE_BIT_PROTNONE + 1)

/* We always extract/encode the offset by shifting it all the way up, and then down again */
#define SWP_OFFSET_SHIFT	(SWP_OFFSET_FIRST_BIT+SWP_TYPE_BITS)

#define MAX_SWAPFILES_CHECK() BUILD_BUG_ON(MAX_SWAPFILES_SHIFT > SWP_TYPE_BITS)

/* Extract the high bits for type */
#define __swp_type(x) ((x).val >> (64 - SWP_TYPE_BITS))

/* Shift up (to get rid of type), then down to get value */
#define __swp_offset(x) (~(x).val << SWP_TYPE_BITS >> SWP_OFFSET_SHIFT)

/*
 * Shift the offset up "too far" by TYPE bits, then down again.
 * The offset is inverted by a binary not operation to make the high
 * physical bits set.
 */
#define __swp_entry(type, offset) ((swp_entry_t) { \
	(~(unsigned long)(offset) << SWP_OFFSET_SHIFT >> SWP_TYPE_BITS) \
	| ((unsigned long)(type) << (64-SWP_TYPE_BITS)) })

#define __pte_to_swp_entry(pte)		((swp_entry_t) { pte_val((pte)) })
#define __swp_entry_to_pte(x)		((pte_t) { .pte = (x).val })

extern int kern_addr_valid(unsigned long addr);
extern void cleanup_highmap(void);

#define HAVE_ARCH_UNMAPPED_AREA
#define HAVE_ARCH_UNMAPPED_AREA_TOPDOWN

#define pgtable_cache_init()   do { } while (0)
#define check_pgt_cache()      do { } while (0)

#define PAGE_AGP    PAGE_KERNEL_NOCACHE
#define HAVE_PAGE_AGP 1

/* fs/proc/kcore.c */
#define	kc_vaddr_to_offset(v) ((v) & __VIRTUAL_MASK)
#define	kc_offset_to_vaddr(o) ((o) | ~__VIRTUAL_MASK)

#define __HAVE_ARCH_PTE_SAME

#define vmemmap ((struct page *)VMEMMAP_START)

extern void init_extra_mapping_uc(unsigned long phys, unsigned long size);
extern void init_extra_mapping_wb(unsigned long phys, unsigned long size);

#include <asm/pgtable-invert.h>

#endif /* !__ASSEMBLY__ */
#endif /* _ASM_X86_PGTABLE_64_H */
