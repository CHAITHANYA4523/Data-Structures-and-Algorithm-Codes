class Solution{
    public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<int> adj[N];
        for(auto &it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> dist(N);
        for(int i=0; i<N; i++) dist[i] = 1e9; 
        dist[src] = 0;
        // we can take distance from dist array for a node so no need to take pair<int,int> in queue
        queue<int> q;
        q.push(src);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int &it:adj[node]){
                // store the minimum distance from source node
                if(dist[node]+1 < dist[it]){
                    dist[it] = dist[node]+1;
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