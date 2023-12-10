class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // {vertical , {level , node->val}}
        map<int, map<int,multiset<int>>> mp; // using multiset to store equal values in the same vertical line
        // {node , {vertical , level}}
        queue<pair<TreeNode* , pair<int , int >>> q;
        q.push({root , {0 , 0}});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            TreeNode* node = it.first;
            int vertical = it.second.first;
            int level = it.second.second;
            mp[vertical][level].insert(node->val);
            if(node->left) q.push({node->left, {vertical-1, level+1}});
            if(node->right) q.push({node->right, {vertical+1, level+1}});
        }
        vector<vector<int>> ans;
         for(auto oneVertical:mp){
        // vec is a vector of int to store one complete vertical .
            vector<int>vec;
            for(auto levelAndSet:oneVertical.second){
                for(auto setElement:levelAndSet.second){
                    vec.push_back(setElement);
                }
            }
            ans.push_back(vec);
        }
        return ans;
    }
};

/*
Time Complexity: The time complexity is O(nlogn) where n is the number of nodes in the tree. This is because we traverse each node once, and for each node, we insert it into a map and a multiset. Insertion into a map has a time complexity of O(logn)  and insertion into a multiset also has a time complexity of O(logn) Therefore, the overall time complexity is O(nlogn)

Space Complexity: The space complexity is O(n) where n is the number of nodes in the tree. This is because we store each node in a map, and in the worst case, if the tree is skewed, we might end up storing all nodes at the same vertical distance, leading to O(n) space complexity. Additionally, we use a queue for the BFS traversal, which in the worst case can hold all nodes of a level. In a perfect binary tree, the last level can have approximately n/2 nodes, so this also contributes to the O(n)
 space complexity.
*/