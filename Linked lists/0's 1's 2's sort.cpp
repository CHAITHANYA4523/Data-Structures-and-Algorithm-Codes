//Approach 1 (rewriting the data)
Node* sortList(Node *head)
{
    int count_0=0;
    int count_1=0;
    int count_2=0;
    Node* temp=head;
    while(temp!=NULL){
       if(temp->data==0) count_0++;
       else if(temp->data==1) count_1++;
       else if(temp->data==2)count_2++;
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL){
        if(count_0 != 0){
            temp->data=0;
            count_0--;
        }
        else if(count_1 !=0){
            temp->data=1;
            count_1--;
        }
        else if(count_2 != 0){
            temp->data=2;
            count_2--;
        }
        temp=temp->next;
    }
     return head;
}

//Approach 2 (creating 3 separate linked lists and merging them )
void insertAtTail(Node* &tail, Node *curr){
    tail->next = curr;
    tail = curr;
}
Node* sortList(Node *head){
    Node* zero_head = new Node(-1);
    Node* zero_tail = zero_head;
    Node* one_head = new Node(-1);
    Node* one_tail = one_head;
    Node* two_head = new Node(-1);
    Node* two_tail = two_head;
    
    Node *temp = head;
    while(temp){
        if(temp->data == 0){
            insertAtTail(zero_tail, temp);
        }
        else if(temp->data == 1){
            insertAtTail(one_tail, temp);
        }
        else{
           insertAtTail(two_tail, temp); 
        }
        temp = temp->next;
    }
    //Merging 3 lists
    //1's are present
    if(one_tail){
        zero_tail->next = one_head->next;
        one_tail->next = two_head->next;
        two_tail->next = NULL;
    }
    else{
       zero_tail->next = two_head->next;
       two_tail->next = NULL; 
    }
    head = zero_head->next;
    delete(zero_head);
    delete(one_head);
    delete(two_head);
    return head;
}