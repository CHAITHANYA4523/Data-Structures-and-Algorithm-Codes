// Approach 1 (brute force)

class Solution {
public:
    // This function checks if a node x exists in the tree rooted at 'root'.
    // If it does, it sets the 'counter' to true.
    void checkLowestCommonAncestor(TreeNode* root, TreeNode* x, TreeNode* &ans, bool &counter){
        if(root == NULL) return;
        if(root->val == x->val){
            counter = true;
            return;
        }
        else{
            checkLowestCommonAncestor(root->left, x, ans, counter);
            checkLowestCommonAncestor(root->right, x, ans, counter);
        }
    }

    // This function performs a depth-first search (DFS) on the tree rooted at 'root'.
    // It checks if nodes p and q exist in the tree. If they do, it sets 'ans' as their lowest common ancestor.
    void dfs(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode* &ans){
        if(root == NULL) return;
        bool counter1 = false, counter2 = false;
        checkLowestCommonAncestor(root, p, ans, counter1);
        checkLowestCommonAncestor(root, q, ans, counter2);
        if(counter1 == true && counter2 == true) ans = root;
        dfs(root->left, p, q, ans);
        dfs(root->right, p, q, ans);
    }

    // This function returns the lowest common ancestor of nodes p and q in the tree rooted at 'root'.
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = new TreeNode(root->val);
        dfs(root, p, q, ans);
        dfs(root, p, q, ans);
        return ans;
    }
};

/*
Time Complexity: The time complexity of this code is O(n^2), where n is the number of nodes in the tree. This is because in the worst case, for each node in the tree, we are traversing all the other nodes to check if they are the same as the given node.

Space Complexity: The space complexity is O(n), where n is the height of the tree. This space is used for the call stack during the recursive calls.
*/

//Approach 2

class Solution {
public:
    bool getPath(TreeNode* root, TreeNode* target, vector<TreeNode*>& path) {
        if (root == NULL) {
            return false;
        }
        path.push_back(root);
        if (root == target) {
            return true;
        }
        if (getPath(root->left, target, path) || getPath(root->right, target, path)) {
            return true;
        }
        path.pop_back();
        return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1, path2;
        getPath(root, p, path1);
        getPath(root, q, path2);
        TreeNode* lca = NULL;
        for (int i = 0; i < min(path1.size(), path2.size()); i++) {
            if (path1[i] == path2[i]) {
                lca = path1[i];
            } else {
                break;
            }
        }
        return lca;
    }
};

// in this approach space complexity is O(n)+O(n)

// Approach 3 

class Solution {
public:
    TreeNode* rec(TreeNode* root, TreeNode* p, TreeNode* q) {
        // If the current node is NULL or is either p or q, return the current node.
        if (root == NULL || root == p || root == q) {
            return root;
        }
        TreeNode* l = rec(root->left, p, q);
        TreeNode* r = rec(root->right, p, q);
        // If both l and r are not NULL, it means that p and q are found on different subtrees.
        // So, the current node is their lowest common ancestor.
        if (l != NULL && r != NULL) {
            return root;
        }
        // If l is NULL, it means that both p and q are on the right subtree. So, return r.
        if (l == NULL) {
            return r;
        }
        // If none of the above conditions are met, it means that both p and q are on the left subtree. So, return l.
        return l;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return rec(root, p, q);
    }
};

/*
The time complexity of this code is O(N), where N is the number of nodes in the tree. This is because in the worst-case scenario, we might have to visit all the nodes of the tree.
The space complexity of this code is O(H), where H
 is the height of the tree. This space is used by the call stack during the recursive calls. In the worst case, if the tree is skewed, the maximum height of the tree is N, so the space complexity is O(N). However, in the average case for a balanced binary tree, the height is log(N), so the space complexity is O(log(N)).
.
*/