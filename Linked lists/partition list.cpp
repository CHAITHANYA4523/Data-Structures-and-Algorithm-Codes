class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy_smaller = new ListNode(0);
        ListNode* dummy_greater_equal = new ListNode(0);
        ListNode* smaller = dummy_smaller;
        ListNode* greater_equal = dummy_greater_equal;

        ListNode* curr = head;

        while (curr) {
            if (curr->val < x) {
                smaller->next = curr;
                smaller = smaller->next;
            } else {
                greater_equal->next = curr;
                greater_equal = greater_equal->next;
            }
            curr = curr->next;
        }

        // Connect the smaller values partition to the greater or equal values partition
        smaller->next = dummy_greater_equal->next;
        // Make sure to terminate the end of the greater or equal values partition
        greater_equal->next = nullptr;

        return dummy_smaller->next;
    }
};
