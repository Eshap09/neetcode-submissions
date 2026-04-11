class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode dummy(0);   // dummy node
        ListNode* t = &dummy;

        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val <= l2->val) {
                t->next = l1;
                l1 = l1->next;
            } else {
                t->next = l2;
                l2 = l2->next;
            }
            t = t->next;
        }

        // Attach remaining nodes
        if (l1 != nullptr) {
            t->next = l1;
        } else {
            t->next = l2;
        }

        return dummy.next;
    }
};