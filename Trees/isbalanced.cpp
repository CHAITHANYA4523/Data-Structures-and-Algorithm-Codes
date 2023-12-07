//Approach 1
class Solution {
public:
    int height(TreeNode* root){
        if(root == NULL) return 0;
        int left = height(root->left);
        int right = height(root->right);
        int ans = max(left, right) + 1;
        return ans;
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);
        bool diff = abs(height(root->left)-height(root->right)) <= 1;
        if(left && right && diff) return true;
        else return false; 
    }
};

//Approacch 2

class Solution {
public:
    pair<bool, int> isBalancedFast(TreeNode* root){
        //base case
        if(root == NULL){
            pair<bool, int> p = make_pair(true, 0);
            return p;
        } 

        pair<bool, int> left = isBalancedFast(root->left);
        pair<bool, int> right = isBalancedFast(root->right);

        bool leftAns = left.first;
        bool rightAns = right.first;
        
        bool diff = abs(left.second - right.second) <= 1;

        pair<bool, int> ans;
        ans.second = max(left.second, right.second)+1;

        if(leftAns && rightAns && diff) ans.first = true;
        else ans.first = false; 

        return ans;
    }
    bool isBalanced(TreeNode* root) { 
        return isBalancedFast(root).first;
    }
};
/*
Time Complexity: O(n)

The time complexity is O(n) because each node in the binary tree is visited exactly once. The function isBalancedFast is a recursive function that traverses each node in the tree once, hence the time complexity is linear.

Space Complexity: O(n)

The space complexity is also O(n). In the worst-case scenario (when the tree is skewed), the maximum height of the tree is n (where n is the number of nodes). Since a function call is made for each node, this would require n amount of space on the call stack. Therefore, the space complexity is linear.
*/