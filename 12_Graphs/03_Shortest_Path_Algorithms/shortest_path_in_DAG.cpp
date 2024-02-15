// Using BFS
class Solution{
    public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<pair<int,int>> adj[N];
         for(auto it: edges){
            adj[it[0]].push_back({it[1], it[2]});
        }
        vector<int> dist(N, 1e9);
        dist[0] = 0; 
        queue<pair<int,int>> q;
        q.push({0,0});
        while(!q.empty()){
            int node= q.front().first;
            q.pop(); 
            for(auto it: adj[node]){
                if(dist[it.first] > dist[node]+ it.second){
                    dist[it.first]= dist[node]+ it.second;
                    q.push(it);
                    
                }
            }
        }
        for(int i=0; i<N; i++){
            if(dist[i] == 1e9) dist[i] = -1;
        }
        return dist;
    }
};

//Using DFS

class Solution {
  private:
    void topoSort(int node, vector <pair<int,int >> adj[], int vis[], stack <int> & st) {
      //This is the function to implement Topological sort. 
      vis[node] = 1;
      for (auto it: adj[node]) {
        int v = it.first;
        if (!vis[v]) {
          topoSort(v, adj, vis, st);
        }
      }
      st.push(node);
    }
  public:
    vector <int> shortestPath(int N, int M, vector<vector<int>> & edges) {
      vector<pair<int, int>> adj[N];
      for (int i = 0; i < M; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adj[u].push_back({v, wt}); 
      }
      // A visited array is created with initially 
      // all the nodes marked as unvisited (0).
      int vis[N] = {0};
      //Now, we perform topo sort using DFS technique 
      //and store the result in the stack st.
      stack < int > st;
      for (int i = 0; i < N; i++) {
        if (!vis[i]) {
          topoSort(i, adj, vis, st);
        }
      }
      //Further, we declare a vector ‘dist’ in which we update the value of the nodes’
      //distance from the source vertex after relaxation of a particular node.

      vector < int > dist(N);
      for (int i = 0; i < N; i++) {
        dist[i] = 1e9;
      }
      dist[0] = 0;
      while (!st.empty()) {
        int node = st.top();
        st.pop();
        for (auto it: adj[node]) {
          int v = it.first;
          int wt = it.second;
          if (dist[node] + wt < dist[v]) {
            dist[v] = wt + dist[node];
          }
        }
      }

      for (int i = 0; i < N; i++) {
        if (dist[i] == 1e9) dist[i] = -1;
      }
      return dist;
    }
};