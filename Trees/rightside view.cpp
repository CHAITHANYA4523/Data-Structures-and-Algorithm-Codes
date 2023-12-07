class Solution {
public:
    void rightView(TreeNode* &root, vector<int> &ans, int level){
        if(root == NULL) return;
        if(ans.size() == level)ans.push_back(root->val);
        rightView(root->right, ans, level+1);
        rightView(root->left, ans, level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        rightView(root, ans, 0);
        return ans;
    }
};

//it can also be solved using bfs

/*
Time Complexity (O(n)):

The worst-case scenario for time complexity occurs in a skewed binary tree where each node only has a right child. In this case, the rightView function traverses all nodes from the root to the deepest rightmost leaf before moving to the left subtree. This results in a time complexity of O(n), where n is the number of nodes.

     1
      \
       2
        \
         3
          \
           4
            \
             5

Space Complexity (O(n)):

The worst-case scenario for space complexity occurs when the binary tree is completely skewed, either to the left or right. In this scenario, the recursion stack will have a maximum height equal to the number of nodes in the tree.

5
 \
  4
   \
    3
     \
      2
       \
        1

*/