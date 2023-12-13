lass Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode*  dummy_head = new ListNode(10000);
        ListNode* curr = head; 
        ListNode* dummy_tail = dummy_head;
        ListNode* next = NULL;

        while(curr){
            //to keep track of unsorted linked list
            next = curr->next;
            //move the dummy_tail pointer towards right until points to NULL
            while(dummy_tail->next != NULL && dummy_tail->next->val < curr->val){
                dummy_tail = dummy_tail->next;
            }
            //insert a node between dummy_tail and curr
            curr->next = dummy_tail->next;
            dummy_tail->next = curr;
            curr = next;
            // Reset dummy_tail to the beginning of the sorted list
            dummy_tail = dummy_head;
        }
        return dummy_head->next;
    }
};