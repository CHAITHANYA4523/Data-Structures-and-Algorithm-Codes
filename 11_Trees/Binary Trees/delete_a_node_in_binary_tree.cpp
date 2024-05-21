
class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(root == NULL) return NULL;
        if(root->left) root->left = removeLeafNodes(root->left, target);
        if(root->right) root->right = removeLeafNodes(root->right, target);
        return root->left == root->right && root->val == target ? NULL : root;
    }
};

