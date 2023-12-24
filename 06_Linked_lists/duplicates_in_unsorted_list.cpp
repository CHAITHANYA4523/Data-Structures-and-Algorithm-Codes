
//using maps
Node *removeDuplicates(Node *head)
{
    if(head == NULL || head->next == NULL) return head;
    unordered_map<int, int> visited;
    Node *temp = head;
    Node *prev = NULL;
    while(temp != NULL){
        if(visited[temp->data] != 1){
            visited[temp->data]++;
            prev = temp;
            temp = temp->next;    
        }
        else{
            prev->next = temp->next;
            temp = temp->next;
        }
    } 
    return head;
}