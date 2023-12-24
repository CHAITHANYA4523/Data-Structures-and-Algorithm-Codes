class Solution {
public:
    void rightView(TreeNode* &root, vector<int> &ans, int level){
        if(root == NULL) return;
        if(ans.size() == level)ans.push_back(root->val);
        rightView(root->right, ans, level+1);
        rightView(root->left, ans, level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        rightView(root, ans, 0);
        return ans;
    }
};

//it can also be solved using bfs

/*
Time Complexity (O(n)):

The worst-case scenario for time complexity occurs in a skewed binary tree where each node only has a right child. In this case, the rightView function traverses all nodes from the root to the deepest rightmost leaf before moving to the left subtree. This results in a time complexity of O(n), where n is the number of nodes.

     1
      \
       2
        \
         3
          \
           4
            \
             5

Space Complexity (O(n)):

The worst-case scenario for space complexity occurs when the binary tree is completely skewed, either to the left or right. In this scenario, the recursion stack will have a maximum height equal to the number of nodes in the tree.

5
 \
  4
   \
    3
     \
      2
       \
        1

*/

//top view of a binary tree

// approach 
/*
use vertical order traversal tecchnique and store node values that come first in each vertiacl line
*/
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        // {vertical, node}
        map<int, int> mp;
        queue<pair<int, Node*>> q;
        q.push({0,root});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int vertical = it.first;
            Node* node = it.second;
            //to add first node of every vertical line
            if(mp.find(vertical) == mp.end()) mp[vertical] = node->data;
            if(node->left) q.push({vertical-1, node->left});
            if(node->right) q.push({vertical+1, node->right});
        }
        vector<int> ans;
        for(auto &itr:mp){
            ans.push_back(itr.second);
        }
        return ans;
    }
};
/*
Time Complexity: The time complexity of the algorithm is O(n) where n
 is the number of nodes in the binary tree. This is because each node is processed exactly once.
Space Complexity: The space complexity of the algorithm is O(n) where n
 is the number of nodes in the binary tree. This is due to the extra space required for the queue and the map. In the worst case, if the binary tree is skewed, the size of the queue can grow up to n nodes. The map also stores up to n nodes.
*/

//Bottom view of a binary tree

/*
similar approach to top view but we add last node value of each vertical line
*/

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        map<int, int> mp;
        queue<pair<int, Node*>> q;
        q.push({0,root});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int vertical = it.first;
            Node* node = it.second;
            mp[vertical] = node->data;
            if(node->left) q.push({vertical-1, node->left});
            if(node->right) q.push({vertical+1, node->right});
        }
        vector<int> ans;
        for(auto &itr:mp){
            ans.push_back(itr.second);
        }
        return ans;
    }
};

