//
// Created by XingfengYang on 2020/6/16.
//

#ifndef __KERNEL_KVMM_H__
#define __KERNEL_KVMM_H__
#include "page.h"
#include "vmm.h"

typedef struct PageTable {
    PageTableEntry pte[KERNEL_PTE_NUMBER * KERNEL_PTE_NUMBER];
} PageTable;

typedef struct Level2PageTable {
    PageTableEntry pte[KERNEL_PTE_NUMBER];
} Level2PageTable;

typedef struct Level1PageTable {
    PageTableEntry pte[KERNEL_L1PT_NUMBER];
} Level1PageTable;

void kernel_vmm_init();
void kernel_vmm_enable();
void kernel_vmm_map(uint32_t virtualAddress);
void kernel_vmm_add_map_hook(void (*func)(uint32_t process));

PageTableEntry* kernel_vmm_get_page_table();

#endif //__KERNEL_KVMM_H__
