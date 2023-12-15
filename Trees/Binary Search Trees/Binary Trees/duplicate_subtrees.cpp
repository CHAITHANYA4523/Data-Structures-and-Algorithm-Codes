
class Solution {
public:
    // Serialize subtrees and check for duplicates using a post-order traversal
    string preorder(TreeNode* &root, unordered_map<string, int> &subtrees, vector<TreeNode*> &res){
        if(root == NULL) return "null";
        string left = preorder(root->left, subtrees, res);
        string right = preorder(root->right, subtrees, res);
        string s = left + "," + right + "," + to_string(root->val);  // Serialize the current subtree
        // we are first checking before updating count of serialised string to avoid multiple insertions of a root into the resultant vector 
        if(subtrees[s] == 1) res.push_back(root); // If a duplicate subtree is found, add to the vector
        subtrees[s]++;
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> subtrees;
        vector<TreeNode*> res;
        preorder(root, subtrees, res);
        return res;
    }
};

/*
Time Complexity:

The time complexity of the serializeSubtrees function is O(n^2), where n is the number of nodes in the binary tree.
n for processing each node and another n for hashing string of length n in worst case(serialisation)

Space Complexity:

The space complexity of the serializeSubtrees function is O(n), because the function creates a string for each subtree in the binary tree.
The space complexity of the findDuplicateSubtrees function is O(n), because it creates an unordered map to store the serialized subtrees and their frequency, and a vector to store the duplicate subtrees.
Therefore, the overall space complexity of the algorithm is O(n).
*/