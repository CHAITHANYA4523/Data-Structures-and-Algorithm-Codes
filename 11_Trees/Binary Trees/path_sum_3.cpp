//brute force Approach 1

class Solution {
public:
    void dfs(TreeNode* root, long long targetSum, long long sum, int &totalPaths){
        if(root == NULL) return;
        sum += root->val;
        if(sum == targetSum){
            totalPaths++;
        }
        dfs(root->left, targetSum, sum, totalPaths);
        dfs(root->right, targetSum, sum, totalPaths);
    }
    void noOfPossiblePaths(TreeNode* root, long long targetSum, long long sum, int &totalPaths){
        if(root == NULL) return;
        dfs(root, targetSum, sum, totalPaths);
        noOfPossiblePaths(root->left, targetSum, 0, totalPaths);
        noOfPossiblePaths(root->right, targetSum, 0, totalPaths);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return 0;
        int totalPaths = 0;
        noOfPossiblePaths(root, targetSum, 0, totalPaths);
        return totalPaths;
    }
};

/*
Time Complexity: The time complexity of your code is O(n^2)where n
 is the number of nodes in the tree. This is because for each node, you’re performing a depth-first search (DFS) operation, which in the worst case can traverse all other nodes in the tree.


Space Complexity: The space complexity of your code is O(n) where n
 is the number of nodes in the tree. This is due to the recursive nature of the DFS and the additional function noOfPossiblePaths, both of which use the call stack and can in the worst case end up storing all nodes in the tree on the stack.
*/

//Approach 2

class Solution {
public:
    long long ans = 0, sum;
    unordered_map<long long,long long> visited;
    void dfs(TreeNode* &root, long long currentSum){
        currentSum += root->val;
        // checking if we already found an interval summing up to that
        ans += visited[currentSum - sum];
        visited[currentSum]++;
        if (root->left) dfs(root->left, currentSum);
        if (root->right) dfs(root->right, currentSum);
        // clearing visited of the last value, for backtracking purposes
        visited[currentSum]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        sum = targetSum;
        // visited set with initial value 0 will help us match from the root
        visited[0] = 1;
        if(root == NULL) return ans;
        dfs(root, 0);
        return ans;
    }
};

/*
The time complexity of this algorithm is O(n), where n is the number of nodes in the tree. This is because each node in the tree is visited exactly once by the DFS traversal.

The space complexity of this algorithm is O(n) in the worst case when the tree is completely unbalanced, e.g., each node has only one child. This is because the maximum space required is equal to the maximum depth of the tree, which is n in the worst case. In the average case of a balanced binary tree, the space complexity would be O(log n), where log n is the height of the tree. This space is used by the DFS stack and the visited hash map. The hash map stores the prefix sum and its frequency up to the current node in the path.
*/