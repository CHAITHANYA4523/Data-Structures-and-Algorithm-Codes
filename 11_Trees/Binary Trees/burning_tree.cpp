class Solution {
private:
    map<Node*, Node*> parent;
    set<Node*> visited;
    int maxTime = 0;
    
    void findParent(Node* node) {
        if (!node) return;
        if (node->left) {
            parent[node->left] = node;
            findParent(node->left);
        }
        if (node->right) {
            parent[node->right] = node;
            findParent(node->right);
        }
    }
    
    void dfs(Node* node, int time) {
        if (!node || visited.find(node) != visited.end()) return;
        
        visited.insert(node);
        maxTime = max(maxTime, time);
        
        if (node->left) dfs(node->left, time + 1);
        if (node->right) dfs(node->right, time + 1);
        if (parent[node]) dfs(parent[node], time + 1);
    }
    
public:
    int minTime(Node* root, int target) {
        findParent(root);
        Node* targetNode = nullptr;
        
        // Find the target node
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* node = q.front();
            q.pop();
            if (node->data == target) {
                targetNode = node;
                break;
            }
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        
        if (!targetNode) return 0;
        
        dfs(targetNode, 0);
        
        return maxTime;
    }
};


//Using BFS 

class Solution {
private:
    map<Node*, Node*> parent;
    set<Node*> visited;
    int t = 0;
    
    void findParent(Node* node) {
        if (!node) return;
        if (node->left) {
            parent[node->left] = node;
            findParent(node->left);
        }
        if (node->right) {
            parent[node->right] = node;
            findParent(node->right);
        }
    }
    
    int burnTree(Node* target) {
        queue<Node*> q;
        q.push(target);
        visited.insert(target);
        int time = 0;
        
        while (!q.empty()) {
            int size = q.size();
            bool burned = false;
            
            for (int i = 0; i < size; ++i) {
                Node* node = q.front();
                q.pop();
                
                if (node->left && visited.find(node->left) == visited.end()) {
                    q.push(node->left);
                    visited.insert(node->left);
                    burned = true;
                }
                if (node->right && visited.find(node->right) == visited.end()) {
                    q.push(node->right);
                    visited.insert(node->right);
                    burned = true;
                }
                if (parent[node] && visited.find(parent[node]) == visited.end()) {
                    q.push(parent[node]);
                    visited.insert(parent[node]);
                    burned = true;
                }
            }
            
            if (burned) ++time;
        }
        
        return time;
    }
    
public:
    int minTime(Node* root, int target) {
        findParent(root);
        Node* targetNode = nullptr;
        
        // Find the target node
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* node = q.front();
            q.pop();
            if (node->data == target) {
                targetNode = node;
                break;
            }
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        
        if (!targetNode) return 0;
        
        return burnTree(targetNode);
    }
};