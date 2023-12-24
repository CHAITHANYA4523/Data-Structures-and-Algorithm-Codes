//Basic approach
// here all the node values are not unique
class Solution {
public:
    //after every call it is creating new sub vectors with reccursion to solve for every sub tree
    int findPosition(int x, vector<int> inorder, int n){
        for(int i=0; i<n; i++){
            if(x == inorder[i]) return i;
        }
        return -1;
    }
    // pass index by reference to keep it's updated value
    TreeNode* solve(vector<int> pre, vector<int> in, int &index, int inOrderStart, int inOrderLast, int n){
        //Base case
        if(index >= n || inOrderStart > inOrderLast){
            return NULL;
        }
        int element = pre[index++];
        TreeNode* root = new TreeNode(element);
        int position = findPosition(element, in, n);

        //recursive  calls 
        root->left = solve(pre, in, index, inOrderStart, position-1, n);
        root->right = solve(pre, in, index, position+1, inOrderLast, n);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preOrderIndex = 0;
        int n = preorder.size();
        // n-1 is the last index of inorder vector and 0 is the inorder first index
        TreeNode* ans = solve(preorder, inorder, preOrderIndex, 0, n-1, n);
        return ans;
    }
};

/*
Time Complexity: The time complexity of the code is O(n^2) where n
 is the number of nodes in the tree. This is because for each node, the findPosition function is called which takes O(n) time. Since this is done for n nodes, the total time complexity becomes O(n^2)

Space Complexity: The space complexity of the code is O(n), due to the extra space used by the recursion stack. In the worst case (for a skewed tree), the maximum depth of the recursive call stack is n

Please note that these complexities can be improved by using a hash map to store the positions of elements in the inorder vector, which would reduce the time complexity of the findPosition function from O(n) to O(1). This would bring down the overall time complexity to O(n)
*/


//Approach for unique node elements in a binary tree using hashmap

class Solution {
public:
    unordered_map<int, int> inMap; // Hash map to store positions of elements in inorder vector
    // pass index by reference to keep it's updated value
    TreeNode* solve(vector<int>& pre, vector<int>& in, int &index, int inOrderStart, int inOrderLast){
        if(index >= pre.size() || inOrderStart > inOrderLast){
            return NULL;
        }
        int element = pre[index++];
        TreeNode* root = new TreeNode(element);
        // Find the position of the current element in inorder vector using the map
        int position = inMap[element];

        // Recursively build the left and right subtrees
        root->left = solve(pre, in, index, inOrderStart, position-1);
        root->right = solve(pre, in, index, position+1, inOrderLast);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preOrderIndex = 0;
        // Fill the map with positions of elements in inorder vector
        for(int i=0; i<inorder.size(); i++){
            inMap[inorder[i]] = i;
        }
        return solve(preorder, inorder, preOrderIndex, 0, inorder.size()-1);
    }
};

/*
Time Complexity: The time complexity of the code is O(n) where n
 is the number of nodes in the tree. This is because each node is visited once during the construction of the tree.

Space Complexity: The space complexity of the code is also O(n)
, due to the extra space used by the hash map inMap and the recursion stack. The hash map stores up to n
 elements, and in the worst case (for a skewed tree), the maximum depth of the recursive call stack is also n.These complexities assume that the operations of the hash map (insertion, deletion, access) are performed in constant time.
*/

//Binary tree from postorder and inorder traversal
/*
In this code note that recursive call is first called for root->right before root->left as the node values are arranged in this fashion root => right => left in postorder vector(traversal)
*/

class Solution {
public:
    unordered_map<int,int> mp;
    TreeNode* solve(vector<int>& in, vector<int>& post, int &index, int inorderStart, int inorderEnd){
        //Base case
        if(index < 0 || inorderStart > inorderEnd){
            return NULL;
        }
        int element = post[index--];
        TreeNode* root = new TreeNode(element);
        int position = mp[element];
        //recursive calls
        root->right = solve(in, post, index, position+1, inorderEnd);
        root->left = solve(in, post, index, inorderStart, position-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int postorderIndex = n-1;
        for(int i=0; i<inorder.size(); i++) mp[inorder[i]] = i;
        TreeNode* ans = solve(inorder, postorder, postorderIndex, 0, n-1);
        return ans;
    }
};


//binary tree construction from postorder and preorder 

class Solution {
public:
    unordered_map<int,int> mp;
    TreeNode* solve(vector<int>& pre, vector<int>& post, int &preIndex, int postStart, int postEnd){
        if(preIndex >= pre.size() || postStart > postEnd){
            return NULL;
        }
        int element = pre[preIndex++];
        TreeNode* root = new TreeNode(element);

        // If there are more elements in the preorder array
        if(preIndex < pre.size()){
            // Find the position of the next element in the preorder array in the postorder array
            int position = mp[pre[preIndex]];
            // If the position is less than postEnd, recursively construct the left and right subtrees
            if(position < postEnd){
                //the nodes present from 0 index to pos index in postorder comes under left subtree
                root->left = solve(pre, post, preIndex, postStart, position);
                // the nodes present at pos+1 to pos-1 comes under right subtree (at pos root node is present so only till pos-1)
                root->right = solve(pre, post, preIndex, position+1, postEnd-1);
            }
        }
        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int n = pre.size();
        int preIndex = 0; 
        for(int i=0; i<post.size(); i++) mp[post[i]] = i;
        return solve(pre, post, preIndex, 0, n-1);
    }
};
