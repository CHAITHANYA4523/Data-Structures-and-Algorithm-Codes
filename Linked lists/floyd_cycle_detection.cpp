//cycle start point
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
if(head == NULL || head->next == NULL){
            return NULL;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next && fast->next->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
               break;
            }
        }
        if(fast == NULL || fast->next == NULL || fast->next->next == NULL) return NULL;
        ListNode* temp = head;
        while(temp->next != NULL){
            if(temp == slow)  return temp;
            temp = temp->next;
            slow = slow->next;
        }
        return NULL;
    }
}

//floyd cycle removal
Node* floydDetectLoop(Node* head){
    if(head==NULL)
       return NULL;
    Node* fast=head;
    Node* slow=head;
    while(slow!=NULL && fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        slow=slow->next;
        if(slow==fast){
            return slow;
        }
    }
    return NULL;
}
Node* startOfLoop(Node* head){
    Node* intersection = floydDetectLoop(head);
    if(intersection==NULL){
        return NULL;
    }
    Node* slow=head;
    while(slow!=intersection){
        slow=slow->next;
        intersection=intersection->next;
    }
    return slow;
}
Node *removeLoop(Node *head)
{
   Node* start=startOfLoop(head);
   if(start==NULL)
      return head;
   Node* temp=start;
   while(temp->next != start){
       temp=temp->next;
   }
   temp->next=NULL;
   return head;
}