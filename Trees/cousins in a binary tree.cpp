//Approach 1
class Solution {
public:
    void getDepthAndParent(TreeNode* root, int depth, TreeNode* parent, TreeNode* &finalParent, int &finalDepth, int x){
        if(root == NULL) return;
        if(root->val == x){
            finalDepth = depth;
            finalParent = parent;
            return;
        }
        getDepthAndParent(root->left, depth+1, root, finalParent, finalDepth, x);
        if(finalDepth != -1) return;
        getDepthAndParent(root->right, depth+1, root, finalParent, finalDepth, x);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        int xDepth = -1;
        int yDepth = -1;
        TreeNode* xParent = NULL;
        TreeNode* yParent = NULL;
        TreeNode* temp = NULL;
        getDepthAndParent(root, 0, temp, xParent, xDepth, x);
        getDepthAndParent(root, 0, temp, yParent, yDepth, y);
        return xDepth == yDepth && xParent != yParent;
    }
};

//Approach 2 
class Solution {
public:
    pair<int, TreeNode*> getDepthAndParent(TreeNode* root, int depth, TreeNode* parent, int x){
        if(root == NULL) return {-1, NULL};
        if(root->val == x){
            return {depth, parent};
        }
        pair<int, TreeNode*> left = getDepthAndParent(root->left, depth+1, root, x);
        if(left.first != -1) return left;
        return getDepthAndParent(root->right, depth+1, root, x);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        pair<int, TreeNode*> xp = getDepthAndParent(root, 0, NULL, x);
        pair<int, TreeNode*> yp = getDepthAndParent(root, 0, NULL, y);
        return xp.first == yp.first && xp.second != yp.second;
    }
};

/*
The advantage of using pairs here is that it allows us to return two values (depth and parent) from the getDepthAndParent function. This makes the code more concise and easier to understand, as we can see the depth and parent are logically grouped together. It also eliminates the need for reference parameters to store these values.

However, it’s important to note that using pairs does not affect the time complexity because the underlying algorithm and the number of operations performed remain the same.
*/