//Approach 1

/*
find the maximum node in left subtree of the node to be deleted and point maximum node's right to right subtree to preserve bst property
*/

class Solution {
public:
    TreeNode* lastNode(TreeNode* root){
        if(root->right == NULL) return root;
        return lastNode(root->right);
    }

    // Function to rearrange the tree after deletion
    TreeNode* helper(TreeNode* root){
        if(root->left == NULL) return root->right;
        else if(root->right == NULL) return root->left;
        // Store the right child of the node
        TreeNode* rightChild = root->right;
        // Find the rightmost node of the left subtree
        TreeNode* leftChild = lastNode(root->left);
        // Make the right child of the rightmost node of the left subtree as the right child of the node
        leftChild->right = rightChild;
        // Return the left child of the node
        return root->left;
    }

    // Function to delete a node from the tree
    TreeNode* deleteNode(TreeNode* root, int key) {
        // If the tree is empty, return NULL
        if(!root) return NULL;
        // If the root is the node to be deleted, rearrange the tree and return
        if(root->val == key){
            return helper(root);
        }
        TreeNode* dummy = root;
        while(root){
            if(root->val > key){
                // If the left child of the node is the node to be deleted, delete the node and break the loop
                if(root->left != NULL && root->left->val == key){
                    root->left = helper(root->left);
                    break;
                }
                else{
                    root = root->left;
                }
            }
            else{
                // If the right child of the node is the node to be deleted, delete the node and break the loop
                if(root->right != NULL && root->right->val == key){
                    root->right = helper(root->right);
                    break;
                }
                else{
                    root = root->right;
                }
            }
        }
        return dummy;
    }
};

/*
Time Complexity: The time complexity is O(h), where h is the height of the binary search tree (BST). This is because in the worst-case scenario, we might have to traverse from the root to the deepest leaf node.

Space Complexity: The space complexity is O(h), due to the recursive stack used by the lastNode function. In the worst-case scenario, the maximum depth of the recursive call stack is the height of the BST.

The height h is logarithmic in the number of nodes n (i.e., h = log(n)). Therefore, for a balanced BST, the time and space complexity can also be expressed as O(log n).
*/


//Approach 2 

/*
find maximum node in left subtree and copy it's value in node to be deleted and delete that maximum node present at leaf position
*/

class Solution {
public:
    TreeNode* maxNode(TreeNode* root){
        while(root->right != NULL) root = root->right;
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return root;
        if(key < root->val) root->left = deleteNode(root->left, key);
        else if(key > root->val) root->right = deleteNode(root->right, key);
        // If key is same as root's key, then this is the node to be deleted
        else {
            // node with only one child or no child
            if(root->left == NULL) {
                TreeNode *temp = root->right;
                delete root;
                return temp;
            }
            else if(root->right == NULL) {
                TreeNode *temp = root->left;
                delete root;
                return temp;
            }
            // node with two children: get the maximum node in the left subtree
            TreeNode* temp = maxNode(root->left);
            // copy the maximum node's value to this node
            root->val = temp->val;
            // delete the maximum node
            root->left = deleteNode(root->left, temp->val);
        }
        return root;
    }
};

/*
Time Complexity: The time complexity is O(h), where h is the height of the tree. This is because in the worst case, you may have to traverse from root to the deepest leaf node. In a balanced binary search tree, the height of the tree is log(n), so the time complexity can also be represented as O(log(n)).

Space Complexity: The space complexity is O(h) due to the recursive stack, where h is the height of the tree. Similar to the time complexity, in a balanced binary search tree, the height of the tree is log(n), so the space complexity can also be represented as O(log(n)).
*/