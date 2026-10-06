#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    // Dummy node simplifies edge cases like removing the head node
    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = head;

    struct ListNode* fast = &dummy;
    struct ListNode* slow = &dummy;

    // Advance fast pointer so that there is a gap of n nodes between fast and slow
    for (int i = 0; i < n; i++) {
        fast = fast->next;
    }

    // Move both fast and slow until fast reaches the last node
    while (fast->next != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    // slow->next is the node to delete
    struct ListNode* nodeToDelete = slow->next;
    slow->next = slow->next->next;
    free(nodeToDelete);

    return dummy.next;
}