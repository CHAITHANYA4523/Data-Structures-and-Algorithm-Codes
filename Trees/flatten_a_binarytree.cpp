//Approach 1

class Solution {
public:
    // right left root order
    // In this technique we are building likend list from the end
    TreeNode* prev = NULL;
    void flatten(TreeNode* root) {
        if(!root) return ;
        flatten(root->right);
        flatten(root->left);
        root->right = prev;
        root->left = NULL;
        prev = root;
    }
};

// time complexity - O(n) and space complexity - O(n)

//Approach 2 (Morris Traversal)

class Solution {
public:
    void flatten(TreeNode* root) { // root is taken without reference use curr = root ans use curr for all operations incase of referenced root.
        TreeNode* prev = NULL;
        while(root != NULL){
            if(root->left != NULL){
                prev = root->left;
                while(prev->right) prev = prev->right; // move to extreme right node in left subtree
                prev->right = root->right; // connect last node in left subtree to root right(to reserve preorder traversal)
                root->right = root->left; // root is followed by left subtree before right subtree (preorder) to form a linked list
                root->left = NULL; // all left pointers should be pointing to NULL
            }
            root = root->right; // if root left subtree is absent move right
        }
    }
};

/*
Time Complexity:
The time complexity of this function is O(n), where n
 is the number of nodes in the binary tree. This is because each node in the tree is visited once.
Space Complexity:
The space complexity of this function is O(1), which means it uses constant extra space. 
*/