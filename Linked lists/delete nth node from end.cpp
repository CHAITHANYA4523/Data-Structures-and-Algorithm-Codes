class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head; 
        ListNode* slow = head;
        for(int i=1; i<=n; i++){
            fast = fast->next;
        }
        // handle edge case: given n is always valid, 
        // if fast reached the end, we need to remove the first element
        if(fast == NULL) return head->next;
//Since we will need access to the node before the target node in order to remove the target node,
// we are going to loop until fast->next != NULL rather than until fast != null, so that we stop one
// node earlier.
        while(fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* nn = new ListNode();
        nn = slow->next;
        slow->next = slow->next->next;
        delete(nn);
        return head;
    }
};