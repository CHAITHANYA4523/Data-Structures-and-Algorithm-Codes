class Solution {
public:
    int count = 0;
    void inorderTraversal(TreeNode* root, int k, int &ans){
        if(!root) return;
        inorderTraversal(root->left, k, ans); 
        count++;
        if(count == k){
            ans = root->val;
            return;
        }
        inorderTraversal(root->right, k, ans); 
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
        inorderTraversal(root, k, ans);
        return ans;
    }
};

/*
Time Complexity: The time complexity of this code is O(n), where n
 is the number of nodes in the tree. This is because in the worst-case scenario, you might have to visit all the nodes of the tree (when k=n).


Space Complexity: The space complexity of this code is O(h), where h
 is the height of the tree. This space is used by the call stack during the recursive calls for the in-order traversal. In the worst case (when the tree is a skewed tree), the height of the tree is n, so the space complexity is O(n)
*/