//Approach 1

class Solution {
public:
    int depth(TreeNode* root){
        if(root == NULL) return 0;
        int leftDepth = depth(root->left);
        int rightDepth = depth(root->right);
        if(leftDepth > rightDepth) return leftDepth+1;
        else return rightDepth+1;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        // we reached the lowest common ancestor both left and right subtrees are deepest leaves
        if(depth(root->left) == depth(root->right)) return root;
        // possibility of deepest leaves are on left subtree
        else if(depth(root->left) > depth(root->right)) root = root->left;
        // else on right subtree
        else root = root->right;
        return lcaDeepestLeaves(root);
    }
};

/*
Time Complexity: The time complexity of the code is O(N^2), where N is the number of nodes in the tree. This is because in the worst-case scenario, we are visiting each node once when we calculate the depth, and for each node, we are calculating the depth of its left and right subtrees. So, the time complexity becomes proportional to N^2.

Space Complexity: The space complexity of the code is O(N), where N is the number of nodes in the tree. This space is used by the system stack for the recursive function calls. In the worst case, if the tree is skewed, the maximum height of the tree (and hence the maximum depth of the recursive call stack) can be N. Therefore, the space complexity is O(N).
*/

//Approach 2 using pairs

class Solution {
public:
    pair<TreeNode*, int> dfs(TreeNode* root){
        //Base case
        if(root == NULL){
            pair<TreeNode*, int> p = {NULL, 0};
            return p;
        }

        pair<TreeNode*, int> ans;
        ans.first = root;
        ans.second = 1;
        if(!root->left && !root->right) return ans;

        //recursive calls
        pair<TreeNode*, int> leftAns = dfs(root->left);
        pair<TreeNode*, int> rightAns = dfs(root->right);
        
        if(leftAns.second == rightAns.second){
            ans.second += leftAns.second;
            ans.first = root;
            return ans;
        }
        else if(leftAns.second > rightAns.second){
            ans.second += leftAns.second;
            ans.first = leftAns.first;
            return ans;
        }
        else{
            ans.second += rightAns.second;
            ans.first = rightAns.first;
            return ans;
        }

    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root).first;    
    }
};

/*
Time Complexity: The time complexity of the code is O(N), where N is the number of nodes in the tree. This is because each node in the tree is visited exactly once by the dfs function.

Space Complexity: The space complexity of the code is O(N), where N is the number of nodes in the tree. This space is used by the system stack for the recursive function calls. In the worst case, if the tree is skewed, the maximum height of the tree (and hence the maximum depth of the recursive call stack) can be N. Therefore, the space complexity is O(N).
*/