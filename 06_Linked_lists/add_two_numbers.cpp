class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0); // creating a dummy list
        ListNode* curr = dummy; // initializing a pointer
        int carry = 0; // initializing our carry with 0 initially
        // while loop will run until l1 OR l2 is not nullptr OR if they both reach nullptr. But our carry has some value in it.
        // We will add that as well into our list
        while (l1 != nullptr || l2 != nullptr || carry == 1) {
            int sum = 0; // initializing our sum
            if (l1 != nullptr) { // adding l1 to our sum & moving l1
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) { // adding l2 to our sum & moving l2
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry; // if we have carry then add it to our sum
            carry = sum / 10; // if we get carry, then divide it by 10 to get the carry
            ListNode* node = new ListNode(sum % 10); // the value we'll get by moduloing it, will become a new node, so add it to our list
            curr->next = node; // curr will point to that new node if we get
            curr = curr->next; // update the current every time
        }
        return dummy->next; // return dummy->next because we don't want the value we have considered in it initially!!
    }
};


//code for numbers given in correct order and leading zeroes handling

class Solution{
private:
    struct Node* reverseList(struct Node* head)
    {
        struct Node* prev = NULL;
        struct Node* nextNode = NULL;
        struct Node* temp = head;
        while(temp != NULL){
            nextNode = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nextNode;
        }
        return prev;
    }

public:
    struct Node* addTwoLists(struct Node* num1, struct Node* num2)
    {
        if(num1 == NULL)
            return num2;
            
        if(num2 == NULL)
            return num1;
        num1 = reverseList(num1);
        num2 = reverseList(num2);
        struct Node* dummy = new Node(-1);
        struct Node* temp = dummy;
        int carry = 0;
        while(num1 != NULL || num2 != NULL || carry){
            int sum = 0;
            if(num1 != NULL){
                sum += num1->data;
                num1 = num1->next;
            }
            if(num2 != NULL){
                sum += num2->data;
                num2 = num2->next;
            }
            if(carry) sum += carry;
            carry = sum/10;
            struct Node* node = new Node(sum%10);
            temp->next = node;
            temp = temp->next;
        }
        dummy->next = reverseList(dummy->next);
        temp = dummy->next;
        while(temp != NULL && temp->data == 0)
            temp = temp->next;
        return temp == NULL ? new Node(0) : temp;
    }
};
