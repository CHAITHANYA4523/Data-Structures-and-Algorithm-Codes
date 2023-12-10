class Solution {
public:
    void paths(TreeNode* &root, string path, vector<string> &ans){
        if(root == NULL) return;
        path += to_string(root->val); 
        // Check if the current node is a leaf  to store the string
        if(root->left == NULL && root->right == NULL){
            ans.push_back(path);
            return;
        }
        // If not a leaf, continue with "->" and explore both subtrees
        path += "->";
        paths(root->left, path, ans); 
        paths(root->right, path, ans); 
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string s = "";
        paths(root, s, ans);
        return ans;
    }
};

/*
the path string is passed by value to the recursive calls of the paths function. This means that each recursive call gets its own copy of the path string. As a result, changes made to path in one recursive call do not affect the value of path in the parent recursive call or any other sibling recursive calls.

In the case of backtracking, as the recursion unwinds, each instance of the path string is essentially "rolled back" to its state before the recursive call. This is because the path parameter in each recursive call is a local variable, and modifications to it are local to that specific call. When a recursive call returns, the local variables, including path, are popped off the call stack.
*/