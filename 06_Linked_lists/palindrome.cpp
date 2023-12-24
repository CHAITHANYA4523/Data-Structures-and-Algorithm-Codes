class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return true; // An empty list or a list with one element is considered a palindrome.
        }

        ListNode* middle = findMiddle(head);
        ListNode* reversedHalf = reverseList(middle->next);

        ListNode* curr = head;
        ListNode* reversedCurr = reversedHalf;

        while (reversedCurr != nullptr) {
            if (curr->val != reversedCurr->val) {
                return false;
            }
            curr = curr->next;
            reversedCurr = reversedCurr->next;
        }

        // Restore the original list (optional, depending on requirements).
        middle->next = reverseList(reversedHalf);

        return true;
    }

private:
    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        while (head != nullptr) {
            ListNode* nextNode = head->next;
            head->next = prev;
            prev = head;
            head = nextNode;
        }
        return prev;
    }
};
