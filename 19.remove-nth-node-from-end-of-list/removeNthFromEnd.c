/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *removeNthFromEnd(struct ListNode *head, int n) {
    struct ListNode dummy;
    dummy.next = head;

    struct ListNode *slow = &dummy;
    struct ListNode *fast = head;
    for (int i = 0; i < n && fast != NULL; i++)
        fast = fast->next;

    while (fast != NULL) {
        slow = slow->next;
        fast = fast->next;
    }

    struct ListNode *toDelete = slow->next;
    slow->next = toDelete->next;
    free(toDelete);

    return dummy.next;
}
