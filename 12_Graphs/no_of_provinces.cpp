class Solution {
private:
    void dfs(int currentNode, vector<int> &visited, vector<vector<int>>& isConnected){
        visited[currentNode] = 1;
        for(int i=0; i<visited.size(); i++){
            if(isConnected[currentNode][i] == 1 && !visited[i]){
                dfs(i, visited, isConnected);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), provinces = 0;
        vector<int> visited(n, 0);
        for(int i=0; i<n; i++){
            if(visited[i] == 0){
                dfs(i, visited, isConnected);
                provinces++;
            }
        }
        return provinces;
    }
};

//Approach: converting adjacency matrix to adjacency list
class Solution {
  private: 
    // dfs traversal function 
    void dfs(int node, vector<int> adjLs[], int vis[]) {
        // mark the more as visited
        vis[node] = 1; 
        for(auto it: adjLs[node]) {
            if(!vis[it]) {
                dfs(it, adjLs, vis); 
            }
        }
    }
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<int> adjLs[V]; 
        
        // to change adjacency matrix to list 
        for(int i = 0;i<V;i++) {
            for(int j = 0;j<V;j++) {
                // self nodes are not considered
                if(adj[i][j] == 1 && i != j) {
                    adjLs[i].push_back(j); 
                    adjLs[j].push_back(i); 
                }
            }
        }
        int vis[V] = {0}; 
        int cnt = 0; 
        for(int i = 0;i<V;i++) {
            // if the node is not visited
            if(!vis[i]) {
                // counter to count the number of provinces 
                cnt++;
               dfs(i, adjLs, vis); 
            }
        }
        return cnt; 
        
    }
};

/*
Time Complexity: O(N) + O(V+2E), Where O(N) is for outer loop and inner loop runs in total a single DFS over entire graph, and we know DFS takes a time of O(V+2E). 

Space Complexity: O(N) + O(N),Space for recursion stack space and visited array.
*/