class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return ""; 
        string s ="";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
           TreeNode* curNode = q.front();
           q.pop();
           if(curNode==NULL) s.append("#,");
           else{
               s.append(to_string(curNode->val)+',');
               q.push(curNode->left);
               q.push(curNode->right);            
           }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL; 
        stringstream s(data);
        string str; 
        getline(s, str, ',');
        TreeNode *root = new TreeNode(stoi(str));
        queue<TreeNode*> q; 
        q.push(root); 
        while(!q.empty()) {
            
            TreeNode *node = q.front(); 
            q.pop(); 
            
            getline(s, str, ',');
            if(str == "#") {
                node->left = NULL; 
            }
            else {
                TreeNode* leftNode = new TreeNode(stoi(str)); 
                node->left = leftNode; 
                q.push(leftNode); 
            }
            
            getline(s, str, ',');
            if(str == "#") {
                node->right = NULL; 
            }
            else {
                TreeNode* rightNode = new TreeNode(stoi(str)); 
                node->right = rightNode;
                q.push(rightNode); 
            }
        }
        return root; 
    }
};

/*
Time Complexity:
Both serialization and deserialization functions have a time complexity of O(N), where N is the number of nodes in the binary tree.
Each node is processed once in a level-order traversal.
Space Complexity:
Both serialization and deserialization functions have a space complexity of O(N).
The space is dominated by the queue used for BFS traversal, which can store up to N/2 nodes in the worst case for a balanced tree.
*/