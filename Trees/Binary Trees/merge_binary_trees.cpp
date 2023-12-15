class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2) return nullptr;
        if(!root1) return root2;
        if(!root2) return root1;
        root1->val += root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        return root1;
    }
};
/*
Time Complexity:
The time complexity of the code is O(n), where 'n' is the total number of nodes in the larger of the two input trees. This is because the code processes each node exactly once. The recursive function mergeTrees is called for each node in the trees, and the work done for each node is constant.

Space Complexity:
The space complexity is O(h), where 'h' is the height of the larger of the two input trees. This is because the code uses recursion, and the maximum depth of the recursion (the maximum height of the call stack) is determined by the height of the larger tree.

In the worst case, the recursive call stack will have a depth equal to the height of the larger tree. Each recursive call consumes space on the call stack, and since there can be at most 'h' recursive calls on the stack at any given time, the space complexity is O(h).
*/