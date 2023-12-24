class Solution {
public:
    // Function to rotate a linked list.
    Node* rotate(Node* head, int k) {
        int count = 0;          // Initialize a counter to keep track of the number of nodes.
        Node *temp = head, *next; // Initialize pointers 'temp' and 'next'.
        // Step 1: Traverse the list to find the length and the 'k-th' node.
        while (temp) {
            count++;             // Increment the counter.
            next = temp->next;   // Store the 'next' node to avoid losing it.
            if (next == NULL)    // If 'next' is NULL, the list is shorter than 'k', so we return the original head.
                return head;
            if (count == k)      // If the count equals 'k', break the loop to identify the 'k-th' node.
                break;
            temp = temp->next;   // Move to the next node.
        }
        // Step 2: Break the list by setting the 'next' pointer of the 'k-th' node to NULL.
        temp->next = NULL;
        // Step 3: Move 'temp' to the end of the list.
        temp = next;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        // Step 4: Connect the end of the rotated part to the original head to complete the rotation.
        temp->next = head;
        return next;            // Return the new head of the rotated list.
    }
};

//Approach(2) (left rotation)
/*
The idea is to traverse the given list to find the last element and store it in a node. 
Now we need to make the next of last element as the current head, which we can do by 
storing head in temporary node. Repeat the process k time.
*/

// Function to rotate a linked list.
Node* rotate(Node* head, int k)
{
    // let us consider the example
    // 10->20->30->40->50->60 - k=4
    // initialising 2 nodes temp and last
    Node* last = head;
    Node* temp = head;
  
    // if head is null or k==0 no rotation is required
    if (head == NULL || k == 0) {
        return head;
    }
  
    // Making last point to the last-node of the given
    // linked list in this case 60
    while (last->next != NULL) {
        last = last->next;
    }
  
    // Rotating the linked list k times, one rotation at a
    // time.
    while (k) {
  
        // Make head point to next of head
        // so in the example given above head becomes 20
        head = head->next;
  
        // Making next of temp as NULL
        // In the above example :10->NULL
        temp->next = NULL;
  
        // Making temp as last node
        // (head)20->30->40->50->60->10(last)
        last->next = temp;
        last = temp;
  
        // Point temp to head again for next rotation
        temp = head;
        k--;
    }
  
    return head;
}


//right rotation

// This is a C++ solution for rotating a linked list to the right by 'k' positions.
class Solution {
public:
    // Function to rotate the linked list to the right by 'k' positions.
    ListNode* rotateRight(ListNode* head, int k) {
        // Check for special cases where rotation is not needed.
        if(head == NULL || k == 0 || head->next == NULL) return head;

        // Initialize two pointers, 'fast' and 'slow', to traverse the linked list.
        ListNode* fast = head;
        ListNode* slow = head;
        int count = 0; // Variable to count the number of nodes in the list.

        // Calculate the total number of nodes in the linked list.
        while(fast){
            count++;
            fast = fast->next;
        }

        // If 'k' is a multiple of the list length, no rotation is needed, return the original head.
        if(k % count == 0) return head;

        // Reset 'fast' pointer to the head of the list.
        fast = head;

        // Move 'fast' pointer 'k%count' positions ahead to find the new head of the rotated list.
        for(int i = 0; i < (k % count); i++){
            fast = fast->next;
        }

        // Move both 'fast' and 'slow' pointers until 'fast' reaches the end of the list.
        while(fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }

        // Update the links to rotate the list.
        fast->next = head; // Connect the last node to the original head.
        head = slow->next; // Update the new head of the rotated list.
        slow->next = NULL; // Set the 'slow' node's next pointer to NULL to terminate the rotated list.

        // Return the new head of the rotated list.
        return head;
    }
};
