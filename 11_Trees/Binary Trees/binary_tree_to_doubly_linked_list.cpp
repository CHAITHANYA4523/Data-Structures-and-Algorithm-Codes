class Solution{
private:    
    Node* head = NULL;
    Node* lastNode = NULL;
    void solve(Node* root){
        if(!root) return;
        solve(root->left);
        if(!head) head = root;
        if(lastNode) lastNode->right = root;
        root->left = lastNode;
        lastNode = root;
        solve(root->right);
    }
  public:
    Node* bToDLL(Node* root) {
        // code here
        solve(root);
        return head;
    }
};