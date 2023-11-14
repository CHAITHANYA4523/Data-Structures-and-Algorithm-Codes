
//Iterative approach
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL && list2 == NULL) return NULL;
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        while(list1 && list2){
            if(list1->val <= list2->val){
                dummy->next = new ListNode(list1->val);
                list1 = list1->next;
            }
            else{
                dummy->next = new ListNode(list2->val);
                list2 = list2->next;
            }
            dummy = dummy->next;
        }
        if(list1 == NULL) dummy->next = list2;
        if(list2 == NULL) dummy->next = list1;
        return temp->next;
    }
};

//recursive approach
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ptr1 = list1;
        ListNode* ptr2 = list2;
        if(ptr1 == NULL){
            return list2;
        }
        if(ptr2 == NULL){
            return list1;
        }
        if(ptr1->val < ptr2->val){
            ptr1->next = mergeTwoLists(ptr1->next, ptr2);
            return ptr1;
        }
        else{
            ptr2->next = mergeTwoLists(ptr1, ptr2->next);
            return ptr2;
        }
    }
};

