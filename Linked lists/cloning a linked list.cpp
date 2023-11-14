//Approach 1(using maps)
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;
        Node* temp = head;
        while(temp){
            mp[temp] = new Node(temp->val);  
            temp = temp->next;
        }
        temp = head;
        while(temp){
            Node* curr = mp[temp];
            Node* nxt = mp[temp->next];
            Node* rand = mp[temp->random];
            curr->next = nxt;
            curr->random = rand;
            temp = temp->next;
        }
        return mp[head];
    }
};

//Approach 2(changing links)

class Solution
{
private:
    // Helper function to insert a new node at the tail of a list
    void insertAtTail(Node* &head, Node* &tail, int d) {
        Node* newNode = new Node(d);
        if(head == NULL) {
            // If the list is empty, set both head and tail to the new node
            head = newNode;
            tail = newNode;
        }
        else {
            // Otherwise, add the new node to the tail and update the tail pointer
            tail -> next = newNode;
            tail = newNode;
        }
    }
  
}

public:
    // Function to copy a linked list with random pointers
    Node *copyList(Node *head) {
        // Step 1: Create a Clone List
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        
        Node* temp = head;
        while(temp != NULL) {
            // Insert nodes into the clone list
            insertAtTail(cloneHead, cloneTail, temp->data);
            temp = temp -> next;
        }
        
        // Step 2: Insert nodes of Clone List in between original List
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        
        while(originalNode != NULL && cloneNode != NULL) {
            // Update the next pointers to connect original and clone lists
            Node* next = originalNode -> next;
            originalNode -> next = cloneNode;
            originalNode = next;
            
            next = cloneNode -> next;
            cloneNode -> next = originalNode;
            cloneNode  = next;
        }
        
        // Step 3: Copy random pointers
        originalNode = head;
        cloneNode = cloneHead;
        
        while(originalNode != NULL && cloneNode != NULL) { 
            // Copy random pointers for clone nodes based on original random pointers
            if(originalNode -> arb != NULL) {
                cloneNode -> arb = originalNode -> arb -> next;
            }
            else {
                cloneNode -> arb  = NULL;
            }
            
            cloneNode = cloneNode -> next;
            originalNode = originalNode -> next;
        }
        
        // Step 4: Revert step 2 changes to restore the original list
        originalNode = head;
        cloneNode = cloneHead;
        
        while (originalNode && cloneNode) {
            originalNode->next = originalNode->next ? originalNode->next->next : originalNode->next;
            cloneNode->next = cloneNode->next ? cloneNode->next->next : cloneNode->next;
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }

        // Step 5: Return the cloned list
        return cloneHead;
    }
};

