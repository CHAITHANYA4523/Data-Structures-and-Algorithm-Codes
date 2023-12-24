class Solution {
public:
    int maxSum(TreeNode* root, int &maxi){
        if(root == NULL) return 0;
        // to avoid negative sum value we are taking max by comparing it with zero
        int leftSum = max(0,maxSum(root->left, maxi)); 
        int rightSum = max(0,maxSum(root->right, maxi));
        maxi = max(leftSum+rightSum+root->val, maxi);
        return (root->val + max(leftSum, rightSum));
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maxSum(root, maxi);
        return maxi;
    }
};

// the problem is quite similar to diameter of the tree which uses height of the tree concept
/*
Time Complexity: O(N).
Reason: We are doing a tree traversal.

Space Complexity: O(N)
Reason: Space is needed for the recursion stack. In the worst case (skewed tree), space complexity can be O(N).
*/