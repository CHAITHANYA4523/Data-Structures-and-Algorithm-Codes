
//BFS Approach
class Solution{
private:
    bool detectCycle(int src, vector<int> adj[], int visited[]){
        queue<pair<int,int>> q;
        visited[src] = 1;
        q.push({src, -1});
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(auto adjacentNode:adj[node]){
                if(!visited[adjacentNode]){
                    visited[adjacentNode] = 1;
                    q.push({adjacentNode, node});
                }
                // If the adjacent node is visited and it is not the parent of the current node, then there is a cycle.
                else if(parent != adjacentNode){
                    return true;
                }
            }
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        int visited[V] = {0};
        // for graph with connected components 
        for(int i=0; i<V; i++){
            if(!visited[i]){
                if(detectCycle(i, adj, visited) == true) return true;
            }
        }
        return false;
    }

};

/*
Time Complexity: O(N + 2E) + O(N), Where N = Nodes, 2E is for total degrees as we traverse all adjacent nodes. In the case of connected components of a graph, it will take another O(N) time.

Space Complexity: O(N) + O(N) ~ O(N), Space for queue data structure and visited array.
*/

//DFS Appraoch

class Solution{
bool detectCycle(int src, int parent, int visited[], vector<int> adj[]){
      visited[src] = 1;
      for(auto adjacentNode:adj[src]){
          if(!visited[adjacentNode]){
            if(detectCycle(adjacentNode, src, visited, adj) == true) return true;  
          }
          //already visited  is not current parent(adjacentNode)
          else if(adjacentNode != parent){
             return true;
          }
      }   
      return false;
  }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        int visited[V] = {0};
        for(int i=0; i<V; i++){
            if(!visited[i]){
                if(detectCycle(i, -1, visited, adj) == true) return true;
            }
        }
        return false;
    }
};

/*
Time Complexity: O(N + 2E) + O(N), Where N = Nodes, 2E is for total degrees as we traverse all adjacent nodes. In the case of connected components of a graph, it will take another O(N) time.

Space Complexity: O(N) + O(N) ~ O(N), Space for recursive stack space and visited array.
*/