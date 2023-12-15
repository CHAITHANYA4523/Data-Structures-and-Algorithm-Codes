
class Solution {
public:
    bool identical(TreeNode* root, TreeNode* subRoot){
        if(root == NULL && subRoot == NULL) return true;
        if(root == NULL || subRoot == NULL || (root->val != subRoot->val)) return false;
        return identical(root->left, subRoot->left) && identical(root->right, subRoot->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL) return false;
        if(identical(root, subRoot)) return true; 
        return (isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot));
    }
};

/*
Time Complexity:
The time complexity of the identical function is O(min(N, M)), where N is the number of nodes in the root tree and M is the number of nodes in the subRoot tree. This is because the function compares corresponding nodes in the two trees recursively.

The isSubtree function calls the identical function for each node in the root tree, and for each call to identical, it involves a recursive traversal of the root and subRoot trees. Therefore, the overall time complexity of the isSubtree function is O(N * min(N, M)), where N is the number of nodes in the root tree and M is the number of nodes in the subRoot tree.

Space Complexity:
The space complexity is determined by the recursive calls in both functions. In the worst case, the maximum depth of the recursion is the height of the tree. Therefore, the space complexity is O(max(height(root), height(subRoot))).

In the worst case, if the tree is unbalanced, the height of the tree can be O(N), where N is the number of nodes. Therefore, the worst-case space complexity is O(N).

It's important to note that the space complexity is influenced by the depth of the recursion, and in the worst case, it could be proportional to the number of nodes in the tree.
*/