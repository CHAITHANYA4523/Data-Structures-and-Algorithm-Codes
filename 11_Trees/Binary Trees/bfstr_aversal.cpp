class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if(root == NULL) return ans;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            for(int i=0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
                level.push_back(node->val);
            }
            ans.push_back(level);
        }
        return ans;
    }
};

//Time Complexity - O(n) as we are traversing all the nodes in the tree datastructure using for loop
//Space Complexity - O(N) in the worst case scenario we will be storing all the nodes in the queue data structure

//Zig Zag order traversal

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans; 
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true; 
        while (!q.empty()) {
            int size = q.size();
            vector<int> level(size);
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                // to decide in which order we need to traverse the nodes
                int index = (leftToRight) ? i:(size-1-i);
                level[index] = node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            leftToRight = !leftToRight; // Switching for every level
            ans.push_back(level);
            //incase of inserting in 1-d array use 
            //ans.insert(ans.end(), level.begin(), level.end());
        }
        return ans;
    }
};
