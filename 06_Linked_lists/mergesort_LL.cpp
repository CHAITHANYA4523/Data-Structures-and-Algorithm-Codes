class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    Node *get_mid(Node *head){
        Node *slow = head;
        Node *fast = head->next;
        while(fast && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    
    Node *merge(Node *left, Node *right){
        if(left == NULL) return right;
        if(right == NULL) return left;
        
        //New Node is created for storage of sorted list
        Node* final_head = new Node(-1);
        Node* final_tail = final_head;
        
        while(left != NULL and right != NULL){
            if(left->data < right->data){
                final_tail->next = left;
                final_tail = left;
                left = left->next;
            }
            else{
                final_tail->next = right;
                final_tail = right;
                right = right->next;
            }
        }
        while(left != NULL){
            final_tail->next = left;
            final_tail = left;
            left = left->next;
        }
        while(right != NULL){
            final_tail->next = right;
            final_tail = right;
            right = right->next;
        }
        final_head = final_head->next;
        return final_head;
    }
    Node* mergeSort(Node* head){
        if(head == NULL || head->next == NULL) return head;
        //divide linked list into two halves
        Node *mid = get_mid(head);
        Node *left = head;
        Node *right = mid->next;
        mid->next = NULL;
        
        left = mergeSort(left);
        right = mergeSort(right);
        //merge two  linked lists in sorted order
        Node *result = merge(left,right);
        return result;
    }
};