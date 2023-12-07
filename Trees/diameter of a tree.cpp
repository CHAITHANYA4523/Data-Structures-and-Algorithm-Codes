class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    int height(Node* root){
        if(root==NULL) return 0;
        int left=height(root->left);
        int right=height(root->right);
        int ans=max(left,right)+1;
        return ans;
    }
    int diameter(Node* root) {
        if(root == NULL) return 0;
        int op1=diameter(root->left);
        int op2=diameter(root->right);
        int op3=height(root->left)+height(root->right);
        int ans=max(op1,max(op2,op3));
        return ans;
    }
};

//Approach 2
class Solution {
  public:
    pair<int,int> diameterFast(Node* root){
        if(root == NULL){
            pair<int,int> p = make_pair(0,0);
            return p;
        }
        pair<int,int> left = diameterFast(root->left);
        pair<int,int> right = diameterFast(root->right);
        
        int op1=left.first;
        int op2=right.first;
        int op3=left.second+right.second;
        pair<int,int> ans;
        ans.first=max(op1,max(op2,op3));
        ans.second=max(left.second,right.second)+1;
        return ans;
    }
    int diameter(Node* root) {
        
        return diameterFast(root).first;
    }
};

//Tilt in a binary tree question
class Solution {
public:
    int summation(TreeNode* root, int &sum){
        if(root == NULL) return 0;
        int left = summation(root->left, sum);
        int right = summation(root->right, sum);
         // count the current tilt
        sum += abs(left-right);
        // return the sum so far
        return left+right+root->val;
    }
    int findTilt(TreeNode* root) {
        int sum = 0;
        if(root) summation(root, sum);
        return sum;
    }
};