/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *node1 = headA;
    struct ListNode *node2 = headB;

    while (node1 != node2) {
        node1 = (node1 == NULL) ? headB : node1->next;
        node2 = (node2 == NULL) ? headA : node2->next;
    }

    return node1;
}
