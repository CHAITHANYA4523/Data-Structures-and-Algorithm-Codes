//Approach 1 using hashmaps

class Solution {
public:
    
    void totalPaths(TreeNode* root, int &ans, unordered_map<int,int> &mp){
        if(root == NULL) return;
        mp[root->val]++;
        if(root->left == NULL && root->right == NULL){
            int count = 0;
            for(auto &x:mp){
                if(x.second == 1) count++;
                // to check where one number is appearing once and another is appearing odd no of times
                if(x.second != 1 && x.second%2 == 1) count++;
            }
            if(count <= 1) ans++;
        }
        totalPaths(root->left, ans, mp);
        totalPaths(root->right, ans, mp);
        mp[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        int ans = 0;
        unordered_map<int, int> mp;
        totalPaths(root,  ans, mp);
        return ans;
    }
};

// test to consider when solving using maps 
// [8,6,9,null,null,null,4,4,1,5,4,null,null,null,null,8]
// for the test case where one number is appearing once and another is appearing odd no of times

/*
In the worst case, this would be the height of the tree. For a balanced binary tree, the height is log(n), and for an unbalanced tree, the height could be n. Therefore, the time complexity of iterating over mp is O(log(n)) in the average case and O(n) in the worst case.

So, the overall time complexity of the algorithm is still O(n) for the DFS traversal, but each traversal has a time complexity of O(log(n)) in the average case and O(n) in the worst case due to the loop over mp. Therefore, the total time complexity is O(n log(n)) in the average case and O(n^2) in the worst case.

The space complexity remains the same as before: O(n) in the worst case and O(log(n)) in the average case. This is due to the space used by the DFS stack and the unordered_map mp.
*/

//Approach 2

/*
Use HashSet
Recursively iterate all paths from root to leaves,
count the occurrence of each digits in an hashset.

Whenever meet an element, toggle it in the set:
If set contains it, remove it.
If set donesn't contain it, add it.

At the leaf node, check if the size of set <= 1.
*/

class Solution {
public:
    unordered_set<int> s;
    int pseudoPalindromicPaths (TreeNode* root) {
        return dfs(root);
    }
    
    int dfs(TreeNode* node) {
        if (!node) return 0;
        // toggle the node value in the hashset
        if (s.count(node->val)) s.erase(node->val);
        else s.insert(node->val);
        int res = dfs(node->left) + dfs(node->right);
        // if it's a leaf node
        if (!node->left && !node->right && s.size() <= 1) res++;
        // undo the choice for the next exploration
        if (s.count(node->val)) s.erase(node->val);
        else s.insert(node->val);
        return res;
    }
};

//Approach 3 using an interger (toggling an integer)

class Solution {
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        return dfs(root, 0);
    }

private:
    int dfs(TreeNode* node, int count) {
        if (!node) return 0;
        count ^= 1 << (node->val);
        int res = dfs(node->left, count) + dfs(node->right, count);
        // If the node is a leaf node (both its left and right children are NULL)
        // Check if the count has only one bit set
        // If so, increment the result by 1
        if (!node->left && !node->right && !(count & (count - 1))) res++;
        return res;
    }
};


/*
The time complexity of the code is O(n), where n is the number of nodes in the tree. This is because each node in the tree is visited exactly once.

The space complexity of the code is also O(n). This is due to the extra space required for the recursion stack in the depth-first search (DFS). In the worst-case scenario (a skewed tree), the maximum depth of the recursive call stack will be equal to the height of the tree, which can be n.
*/