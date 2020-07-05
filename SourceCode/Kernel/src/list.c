//
// Created by XingfengYang on 2020/7/2.
//
#include <list.h>

KernelStatus klist_insert(ListNode *list, ListNode *node) {
    if (list->next != nullptr) {
        list->next->prev = node;
        node->next = list->next;
    }
    node->prev = list;
    list->next = node;
}

ListNode *klist_remove_node(ListNode *node) {

    if (node->next == nullptr && node->prev == nullptr) {
        return node;
    }

    if (node->next == nullptr && node->prev != nullptr) {
        node->prev->next = nullptr;
        node->prev = nullptr;
        return node;
    }

    if (node->prev == nullptr && node->next != nullptr) {
        node->next->prev = nullptr;
        node->next = nullptr;
        return node;
    }

    ListNode *prev = node->prev;
    ListNode *next = node->next;

    prev->next = next;
    next->prev = prev;

    node->next = nullptr;
    node->prev = nullptr;

    return node;
}

uint32_t klist_size(ListNode *node) {
    ListNode *first = node;
    while (first->prev != nullptr) {
        first = first->prev;
    }

    uint32_t size = 0;
    while (first->next != nullptr) {
        first = first->next;
        size++;
    }

    return size;
}