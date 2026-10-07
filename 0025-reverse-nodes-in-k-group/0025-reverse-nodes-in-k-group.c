/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if (!head || k <= 1) {
        return head;
    }

    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = head;

    struct ListNode* prevGroupEnd = &dummy;

    while (1) {
        // 1. Check if there are at least k nodes remaining
        struct ListNode* kth = prevGroupEnd;
        for (int i = 0; i < k && kth != NULL; i++) {
            kth = kth->next;
        }

        // If fewer than k nodes remain, leave them as they are
        if (kth == NULL) {
            break;
        }

        struct ListNode* nextGroupStart = kth->next;
        struct ListNode* curr = prevGroupEnd->next;
        struct ListNode* prev = nextGroupStart;

        // 2. Reverse k nodes
        while (curr != nextGroupStart) {
            struct ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        // 3. Connect the previous group's end to the new head of this reversed group
        struct ListNode* groupStart = prevGroupEnd->next;
        prevGroupEnd->next = kth;
        prevGroupEnd = groupStart;
    }

    return dummy.next;
}