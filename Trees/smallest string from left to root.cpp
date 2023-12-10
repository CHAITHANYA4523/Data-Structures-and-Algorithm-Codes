
class Solution {
public:
    void dfs(TreeNode* root, string &ans, string tempString){
        if(root == NULL) return;
        // to store current node alphabet followed by tempString as we need string starting from leaf and going till root
        tempString = static_cast<char>('a' + root->val) + tempString;
        if(root->left == NULL && root->right == NULL){
            if (tempString < ans || ans.empty()) {
                ans = tempString;
            }
        }
        dfs(root->left, ans, tempString);
        dfs(root->right, ans, tempString);
    }
    string smallestFromLeaf(TreeNode* root) {
        string ans = "", tempString = "";
        dfs(root, ans, tempString);
        return ans;
    }
};

/*

Time complexity: O(N)

In the worst case, we visit each node once, where N is the number of nodes in the binary tree. This is because we perform a depth-first search (DFS) traversal of the entire tree.
Space complexity: O(H)

In the worst case, the recursion depth of the DFS is equal to the height of the tree (H). The space complexity is determined by the maximum depth of the function call stack during the recursion.
In the average case, for a balanced binary tree, the height is log(N), so the space complexity would be O(log(N)).
In the worst case, for a skewed binary tree, the height is N, so the space complexity would be O(N).
*/