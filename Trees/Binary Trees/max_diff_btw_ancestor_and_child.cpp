//Appraoch 
/*
try to calculate maximum and minimum value nodes and take their difference.
*/
class Solution {

public:
    int maxAncestorDiff(TreeNode* root, int mini = INT_MAX, int maxi = INT_MIN) {
        // base case
        if (!root) return (maxi - mini);
        mini = min(mini, root->val);
        maxi = max(maxi, root->val);
        return max(maxAncestorDiff(root->left, mini, maxi), maxAncestorDiff(root->right, mini, maxi));
    }
};

/*
Time Complexity : O(n)
Space Complexity : O(h) where h is the height of the tree [If we don't count the recursive stack then its O(1)]
*/