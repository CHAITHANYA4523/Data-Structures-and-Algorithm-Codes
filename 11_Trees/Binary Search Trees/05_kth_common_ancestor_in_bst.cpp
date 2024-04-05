/*Approach: try to find out the path of Lowest common ancestor, and obtain kth index 
value from the path array if the kth index is non negative else return -1.
*/
class Solution{
private:
    void getPath(Node* root, int x, int y, vector<int>& path){
        if(root == NULL) return;
        path.push_back(root->data);
        //lca is present in left subtree
        if(root->data > x && root->data > y){
            getPath(root->left, x, y, path);
        }
        //lca is present in right subtree
        if(root->data < x && root->data < y){
            getPath(root->right, x, y, path);
        }
    }
public:
    /*You are required to complete below function */
    int kthCommonAncestor(Node *root, int k,int x, int y){
        vector<int> path;
        getPath(root, x, y, path);
        int lcaIndex = path.size()-1;
        int kthIndex = lcaIndex - k + 1;
        if(kthIndex < 0) return -1;
        return path[kthIndex];
    }
};

//lca in BST

class Solution{
public:
    Node* lcaInBst(Node* root, int x, int y){
        if(root == NULL) return;
        //lca is present in left subtree
        if(root->data > x && root->data > y){
            getPath(root->left, x, y, path);
        }
        //lca is present in right subtree
        if(root->data < x && root->data < y){
            getPath(root->right, x, y, path);
        }
        //if one of x or y is lca
        if(root->data == x || root->data == y){
            return root;
        }
        //condition for lca
        //if (root->data > x && root->data < y) || (root->data < x && root->data > y)
        return root;
    }
};