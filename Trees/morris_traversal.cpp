// Morris Traversal of a binary tree (inorder)

vector<int> morrisTraversal(TreeNode* root){
    vector<int> inorder;
    TreeNode* curr = root;
    if(curr->left == NULL){
        inorder.push_back(curr->val);
        curr = curr->right;
    }
    else{
        TreeNode* prev = curr->left;
        while(prev->right && prev->right != curr){
            prev = prev->right;
        }
        if(prev->right == NULL){
            prev->right = curr;
            curr = curr->left;
        }
        else{ // prev->right is pointing to curr(already Threaded) so remove the thread
            prev->right = NULL;
            inorder.push_back(curr->val);
            curr = curr->right;
        }
    }
    return inorder;
}
// Morris Traversal of a binary tree (preorder)

vector<int> morrisTraversal(TreeNode* root){
    vector<int> preorder;
    TreeNode* curr = root;
    if(curr->left == NULL){
        preorder.push_back(curr->val);
        curr = curr->right;
    }
    else{
        TreeNode* prev = curr->left;
        while(prev->right && prev->right != curr){
            prev = prev->right;
        }
        if(prev->right == NULL){
            prev->right = curr;
            preorder.push_back(curr->val); // prev->right is now pointing to the current root which can be stored in the preorder travesal
            curr = curr->left;
        }
        else{ // prev->right is pointing to curr(already Threaded) so remove the thread
            prev->right = NULL; 
            curr = curr->right;
        }
    }
    return preorder;
}

/*
Time Complexity:
The time complexity of the algorithm is O(n), where nis the number of nodes in the binary tree. This is because each node is visited at most twice - once when it is first encountered, and once when it is ‘revisited’ after its left subtree has been fully traversed.

Space Complexity:
The space complexity of the algorithm is O(1), which means it uses constant extra space.
*/

/*
Example Dry run:
    1
   / \
  2   3
 / \
4   5

1) Initialize curr as the root node (1).

2)While curr is not NULL, check if curr has a left child.

3)Since curr (1) has a left child (2), find the rightmost node in curr’s left subtree (which is 5 in this case).

4)If the rightmost node’s right child is NULL, set its right child to curr and move curr to its left child.

5)Now, curr is at 2. Again, it has a left child (4). The rightmost node in curr’s left subtree is 4. Set the right child of 4 to curr (2) and move curr to its left child.

6)Now, curr is at 4. It doesn’t have a left child, so add curr’s value to the inorder vector and move curr to its right child (which is 2 due to threading).

7)Now, curr is back at 2. This time, the rightmost node in its left subtree (4) already points to curr, so we remove the thread (set right child of 4 to NULL), add curr’s value to inorder, and move curr to its right child (which is 1 due to threading).

8)Now, curr is back at 1. The rightmost node in its left subtree (5) already points to curr, so we remove the thread (set right child of 5 to NULL), add curr’s value to inorder, and move curr to its right child (3).

9)Node 3 doesn’t have a left child, so add its value to inorder and set curr to its right child (which is NULL).

10)Now that curr is NULL, we’re done.

The inorder vector after the traversal is [4, 2, 5, 1, 3], which is the correct inorder traversal of the binary tree.
*/