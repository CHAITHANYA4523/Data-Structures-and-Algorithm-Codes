class Solution{
    public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> dist(V, 1e8);
        dist[S] = 0;
        //N-1 relaxatoins
        for(int i=0; i<V-1; i++){
            for(auto it:edges){
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                if(dist[u] != 1e8 && dist[u]+wt < dist[v]){
                    dist[v] = dist[u]+wt;
                }
            }
        }
        //for Nth relaxation to check for negative cycle
        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if(dist[u] != 1e8 && dist[u]+wt < dist[v]){
                return {-1};    
            }
        }
        return dist;
    }
};

/*
Time Complexity: O(V*E), where V = no. of vertices and E = no. of Edges.

Space Complexity: O(V) for the distance array which stores the minimized distances.
*/