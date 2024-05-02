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
        while(!q.empty()){
            
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

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        buildString(root, s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream s(data);
        return buildTree(s);
    }

private:
    void buildString(TreeNode* root, string& s) {
        if(!root) {
            s += "#,";
            return;
        }
        s += to_string(root->val) + ',';
        buildString(root->left, s);
        buildString(root->right, s);
    }

    TreeNode* buildTree(stringstream& s) {
        string str;
        getline(s, str, ',');
        if(str == "#") return NULL;
        TreeNode *node = new TreeNode(stoi(str));
        node->left = buildTree(s);
        node->right = buildTree(s);
        return node;
    }
};

/*
Time Complexity:
For serialize, the time complexity is O(n), where n is the number of nodes in the tree. This is because each node is visited exactly once during the serialization process.
For deserialize, the time complexity is also O(n), as each node is created exactly once.
Space Complexity:
For serialize, the space complexity is O(n). This is because the serialized string contains n nodes, and each node contributes a constant amount of space (for the node value and the comma separator).
For deserialize, the space complexity is O(n). This is due to the space required for the call stack during the recursive tree construction, which in the worst case (for a skewed tree) could be n.
*/

//Using Arrays
class Solution{
    public:
    //Function to serialize a tree and return a list containing nodes of tree.
    void dfs(Node* root, vector<int> &ans){
        if(root == NULL){
            ans.push_back(-1);
            return;
        } 
        ans.push_back(root->data);
        dfs(root->left, ans);
        dfs(root->right, ans);
    }
    vector<int> serialize(Node *root){
        vector<int> ans;
        dfs(root, ans);
        return ans;
    }
    int idx = 0;
    //Function to deserialize a list and construct the tree.
    Node * deSerialize(vector<int> &A){
        if(idx == A.size()) return NULL;
        int value = A[idx];
        idx++;
        if(value == -1){
            return NULL;
        }
        //access in pre-order traversal format as we generated A has preordered elements
        Node* root = new Node(value);
        root->left = deSerialize(A);
        root->right = deSerialize(A);
        return root;
    }
};