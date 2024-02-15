//using BFS
// similar to cylce detection problem in a directed graph
class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int> topo;
        vector<int> inDegree(n, 0);
        vector<int> adj[n];
        queue<int> q;
        for (auto it : prerequisites) {
            // it is a vector of 2 integers and it[0] is first element and it[1] is second element
			adj[it[1]].push_back(it[0]);
            inDegree[it[0]]++;
		}
        for(int i=0; i<n; i++){
            if(inDegree[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:adj[node]){
                inDegree[it]--;
                if(inDegree[it] == 0) q.push(it);
            }
        }
        if(topo.size() == n) return true;
        return false;
    }
};

/*
time and space compleixities are similar to kahn's algo
*/

//course schedule 2

class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<int> topo;
        vector<int> inDegree(n, 0);
        vector<int> adj[n];
        queue<int> q;
        for (auto it : prerequisites) {
            // it is a vector of 2 integers and it[0] is first element and it[1] is second element
			adj[it[1]].push_back(it[0]);
            inDegree[it[0]]++;
		}
        for(int i=0; i<n; i++){
            if(inDegree[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:adj[node]){
                inDegree[it]--;
                if(inDegree[it] == 0) q.push(it);
            }
        }
        if(topo.size() == n) return topo;
        return {};
    }
};