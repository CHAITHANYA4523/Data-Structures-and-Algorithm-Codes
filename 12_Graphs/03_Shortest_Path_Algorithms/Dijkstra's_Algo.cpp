// Using Priority Queue
class Solution{
    public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S){
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(V, 1e9);
        dist[S] = 0;
        // {distance, node}
        pq.push({0, S});
        while(!pq.empty()){
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();
            for(auto it:adj[node]){
                int edgeWeight = it[1];
                int adjNode = it[0];
                if(dis + edgeWeight < dist[adjNode]){
                    dist[adjNode] = dis + edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        for(int i=0; i<V; i++){
            if(dist[i] == 1e9) dist[i] = -1;
        }
        return dist;
        
    }
};

/*
- **Time Complexity**: The time complexity of this algorithm is O((V+E)log V), where V is the number of vertices and E is the number of edges in the graph. This is because, in the worst case, every vertex and every edge will be processed in the priority queue. Here, the operations include extracting the minimum from the priority queue and updating the distances of the vertices, which take logarithmic time.

- **Space Complexity**: The space complexity is O(V), due to the distance array and the priority queue. In the worst case, all the nodes of the graph will be in the priority queue, so the space complexity is linear in the number of vertices V.
*/

