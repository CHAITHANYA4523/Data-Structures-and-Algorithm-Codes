class Solution {
private:
    int dfs(TreeNode* &root, int &moves){
        if(root == NULL) return 0;
        int left = dfs(root->left, moves);
        int right = dfs(root->right, moves);
        moves += abs(left) + abs(right);
        //-1 because evey node should have exactly one coin
        return root->val + left + right - 1;
    }
public:
    int distributeCoins(TreeNode* root) {
        int moves = 0;
        dfs(root, moves);
        return moves;
    }
};