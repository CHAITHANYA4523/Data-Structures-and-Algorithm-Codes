//Using Kahn's algo or BFS
class Solution{
    public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
      vector<int> topo;
      queue<int> q;
      int inDegree[V] = {0};
      for(int i=0; i<V; i++){
          for(auto it:adj[i]){
            inDegree[it]++;
          }
      }
      for(int i=0; i<V; i++){
        if(inDegree[i] == 0){
        q.push(i);
        }
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
      if(topo.size() == V){
        return false;
      }
      return true;
    }
};

/*
The time complexity is O(V + E), where V is the number of vertices and E is the number of edges in the directed graph. This is because the solution uses a modified BFS (Kahn's algorithm) to traverse the graph and update in-degrees.

The space complexity is also O(V + E) as it uses additional space for the in-degree array (O(V)) and the queue (O(V + E)).
*/

//Using DFS approach

/* 
intuition

vis[] keeps track of whether a node has been visited during the DFS traversal, and pathvis[] keeps track of the nodes in the current path. If a node is encountered that is already in the current path, then a cycle exists.
*/
class Solution {
  public:
    bool dfs(int node,vector<int>adj[],int vis[],int pathvis[]){
        vis[node] = 1;
        pathvis[node] = 1;
        for(auto it:adj[node]){
            if(vis[it]==0){
                if(dfs(it,adj,vis,pathvis)==true)return true;
            }
            //node is visited and it is also present in current path(current dfs calls)
            else if(pathvis[it]) return true;
        }
        //mark unvisited before backtracking(as it is no more part of dfs calls)
        pathvis[node]=0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]){
        int vis[V]={0};
        int pathvis[V]={0};
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,pathvis)==true) return true;
            }
        }
        return false;
    }
};

/*
Time Complexity: The time complexity of this code is O(V+E), where V is the number of vertices (nodes) and E is the number of edges in the graph. This is because each node and each edge will be explored once by the depth-first search.

Space Complexity: The space complexity of this code is O(V), where V is the number of vertices (nodes) in the graph. This is due to the space required for the vis and pathvis arrays, which have a size proportional to the number of nodes, and the space required for the recursion stack in the depth-first search, which in the worst case will need to store a path containing all nodes.
*/