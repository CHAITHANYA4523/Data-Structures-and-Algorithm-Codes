class Solution {
public:
    ListNode* findMiddle(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* current = head;

        while (current) {
            ListNode* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
    void mergeLists(ListNode* list1, ListNode* list2) {
        while (list1 && list2) {
            // Save the next nodes after the current nodes.
            ListNode* next1 = list1->next;
            ListNode* next2 = list2->next;
            // Update the next pointers to interleave the nodes.
            list1->next = list2;
            list2->next = next1;
            // Move to the next nodes in both lists.
            list1 = next1;
            list2 = next2;
        }
    }
    void reorderList(ListNode* head) {
        if (!head || !head->next) {
            return;
        }
        ListNode* middle = findMiddle(head);
        ListNode* secondHalf = middle->next;
        middle->next = nullptr; // Split the list into two halves.
        secondHalf = reverseList(secondHalf);
        mergeLists(head, secondHalf);
    }
};

/* Another method of merging linked lists
void reorderList(ListNode* head) {
        ListNode* mid = getMiddle(head);
        ListNode* nextPart = mid->next;
        mid->next = NULL;

        //two pointer:
        ListNode* l1 = head;
        ListNode* l2 = reverseList(nextPart);

        ListNode* result = new ListNode(-1);
        ListNode* res = result;

        while(l1 or l2){
            if(l1) {
                res->next = l1;
                res = res->next;
                l1 = l1->next;
            }
            if(l2){
                res->next = l2;
                res = res->next;
                l2 = l2->next;              
            }
        }
        res->next = NULL;
        result->next = NULL;
        return;
    }
*/


/* stack approach
class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head) {
            return;
        }
        ListNode *slow = head, *fast = head, *curr = head, *nextNode = nul;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        stack<ListNode*> backup;
        while (slow) {
            backup.push(slow);
            slow = slow->next;
        }
        //now we need to make whole list
        while (!backup.empty()) {
            ListNode *top = backup.top();
            backup.pop();
            // this case would occur only for odd number of elements 
            if (curr == top) {
                break;
            }
            // Save the original next node of 'curr' to ensure the continuity of the list.
            nextNode = curr->next;
            // Update 'curr->next' to point to the top node from the backup stack.
            curr->next = top;
            // Connect the top node to the previously saved next node to maintain the list's structure.
            top->next = nextNode;
            // Move 'curr' to the next node in the original order of the list for further processing.
            curr = nextNode;
        }
        curr->next = nul;
    }
};
*/