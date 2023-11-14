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
