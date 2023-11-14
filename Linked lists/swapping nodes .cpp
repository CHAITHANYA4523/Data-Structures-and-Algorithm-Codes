class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        // Initialize two pointers, 'fast' and 'slow', both initially pointing to the head of the linked list.
        ListNode* fast = head;
        ListNode* slow = head;
        
        // Move 'fast' k-1 positions ahead to reach the kth node from the beginning.
        for(int i = 1; i < k; i++){
            fast = fast->next;
        }
        
        // 'fast' is now pointing to the kth node from the beginning, and 'slow' still points to the head.
        ListNode* first = fast;
        
        // Move 'fast' to the end of the list while moving 'slow' along with it until 'fast' reaches the end.
        while(fast->next){
            fast = fast->next;
            slow = slow->next;
        }
        
        // 'slow' is now pointing to the kth node from the end of the list.
        ListNode* second = slow;
        
        // Swap the values of the kth nodes from both ends.
        swap(first->val, second->val);
        
        // Return the head of the modified linked list.
        return head;
    }
};
