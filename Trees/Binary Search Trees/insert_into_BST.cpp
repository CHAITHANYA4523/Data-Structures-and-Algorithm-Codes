// Insert at leaf node to form bst

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* temp = new TreeNode(val);
        if(root == NULL) return temp;
        TreeNode* curr = root;
        while(true){
            if(curr->val >= val){
                if(curr->left != NULL) curr = curr->left;
                else{
                    curr->left = temp;
                    break;
                }
            } 
            else{
                if(curr->right != NULL) curr = curr->right;
                else{
                    curr->right = temp;
                    break;
                }
            }
            
        }
        return root;
    }
};

// Time and Space complexities are - O(height of Bst)
/*my failed test case - 
[8,null,55,39,null,11,null,null,23,null,null]
17
           8
            \
            55
            /  \
          39  null
        /  \
      11  null
       /  \
    null  23
            \
            17
*/