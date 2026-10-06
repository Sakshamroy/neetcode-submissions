#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// Helper function to merge two sorted linked lists
static struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy;
    struct ListNode* tail = &dummy;
    dummy.next = NULL;

    while (l1 != NULL && l2 != NULL) {
        if (l1->val <= l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    tail->next = (l1 != NULL) ? l1 : l2;
    return dummy.next;
}

// Divide and conquer helper
static struct ListNode* mergeRange(struct ListNode** lists, int left, int right) {
    if (left == right) {
        return lists[left];
    }
    if (left > right) {
        return NULL;
    }

    int mid = left + (right - left) / 2;
    struct ListNode* l1 = mergeRange(lists, left, mid);
    struct ListNode* l2 = mergeRange(lists, mid + 1, right);

    return mergeTwoLists(l1, l2);
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (lists == NULL || listsSize == 0) {
        return NULL;
    }
    return mergeRange(lists, 0, listsSize - 1);
}