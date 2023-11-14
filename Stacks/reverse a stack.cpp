
//using recursion
void insertAtBottom(stack<int>& s, int x){
    //base case
    if(s.empty()){
        s.push(x);
        return;
    }
    int num = s.top();
    s.pop();
    //recursive call
    insertAtBottom(s, x);
    s.push(num);
}

void reverseStack(stack<int> &stack) {
    //base case
    if(stack.empty()) return;
    int x = stack.top();
    stack.pop();
    //recursive call
    reverseStack(stack);
    //insert element at bottom
    insertAtBottom(stack, x);

}