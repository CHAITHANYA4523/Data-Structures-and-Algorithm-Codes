
//Floor in a BST
class Solution{
public:
    int floor(Node* root, int x) {
         if (root == NULL) return -1;
        int ans=0;
        while(root!=NULL){
            if(root->data == x){
                ans = root->data;
                break;
            }else if(root->data < x){
                ans = root->data;
                root = root->right;
            }else{
                root = root->left;
            }
        }
        if(ans == 0){
            return -1;
        }
        return ans;
    }
};


//Ceil in a BST
class Solution{
public:
    int floor(Node* root, int x) {
         if (root == NULL) return -1;
        int ans=0;
        while(root!=NULL){
            if(root->data == x){
                ans = root->data;
                break;
            }else if(root->data > x){
                ans = root->data;
                root = root->left;
            }else{
                root = root->right;
            }
        }
        if(ans == 0){
            return -1;
        }
        return ans;
    }
};

// Time and space complexities are - O(height of a binary tree)