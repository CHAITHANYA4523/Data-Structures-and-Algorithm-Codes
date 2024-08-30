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
- **Time Complexity**: 
pseudo code
    while(!pq.empty()){ -> O(V)
                node = pq.top() -> O(log V)
                for(iterating over adjacent nodes){ -> no.of edges (ne = V-1) most dense graph case where V-1 nodes are adjacent to a vertex

                    if(condition){
                        update distance
                        pq.push(); -> O(log V)
                    }
                }
            }
    }

 => O(V(pop from heap + no of edges on vertex * push into priority queue))
 => O(V(log(heap size) + ne * log(heap size)))  in worst case ne = V-1 (dense graph)
 => O(V(log(heap size)(ne + 1)))
 => O(V(log(heap size)(V-1 + 1)))
 => O(V(log(heap size)(V)))
 => O(V^2(log(heap size))) heap size is equal to V^2 (dense graph each node has V-1 adjnodes)
 => O(V^2(log(V^2))) v^2 = E because every node has V-1 adjacent nodes i.e V-1(V) ~ V^2
 => O(E(2*log(V)))

- **Space Complexity**: The space complexity is O(V), due to the distance array and the priority queue. In the worst case, all the nodes of the graph will be in the priority queue, so the space complexity is linear in the number of vertices V.
*/

//Dikjstra using set for optimised complexity

class Solution{
    public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S){
        //{distance, node}
        set<pair<int,int>> s;
        s.insert({0, S});
        vector<int> dist(V, 1e9);
        dist[S] = 0;
        while(!s.empty()){
            // s.begin() is an iterator so dereference it to get the values
            auto it = *(s.begin());
            int dis = it.first;
            int node = it.second;
            s.erase(it);
            for(auto itr : adj[node]){
                int adjNode = itr[0];
                int edgeWeight = itr[1];
                if(dis + edgeWeight < dist[adjNode]){
                    //erase the pair from the set if the distance now obtained is 
                    //smaller than previous distance 
                    // if dist[adjNode] is not 1e9 then it is previously visited by some other node as it will overwrite 1e9
                    if(dist[adjNode] != 1e9){
                        s.erase({dist[adjNode], adjNode});
                    }
                    dist[adjNode] = dis + edgeWeight;
                    s.insert({dist[adjNode], adjNode});
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
Generating shortest path

for(auto it:adj[node]){
			int adjNode = it.first;
			int edgeW = it.second;
			if(distance+edgeW < dist[adjNode]){
				dist[adjNode] = distance+edgeW;
				parent[adjNode] = node;
				pq.push({dist[adjNode], adjNode});
			}
		}
}
vector<int> restore_path(int s, int t, vector<int> const& p) {
    vector<int> path;
    for (int v = t; v != s; v = p[v])
        path.push_back(v);
    path.push_back(s);
    reverse(path.begin(), path.end());
    return path;
}
*/


//keep track of all paths from source to destination
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S using Dijkstra's Algorithm.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S, vector<vector<int>>& parent) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(V, 1e9);
        dist[S] = 0;
        pq.push({0, S});

        while (!pq.empty()) {
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();

            for (auto it : adj[node]) {
                int adjNode = it[0];
                int edgeWeight = it[1];
                
                if (dis + edgeWeight < dist[adjNode]) {
                    dist[adjNode] = dis + edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                    parent[adjNode].clear(); // Clear all previous parents since we found a shorter path
                    parent[adjNode].push_back(node);
                } else if (dis + edgeWeight == dist[adjNode]) {
                    parent[adjNode].push_back(node); // Another path found with the same shortest distance
                }
            }
        }

        return dist;  // Return distances
    }

    // Helper function to perform DFS and find all paths from source to target
    void dfs(int node, int S, vector<vector<int>>& parent, vector<int>& path, vector<vector<int>>& allPaths) {
        if (node == S) {
            path.push_back(node);
            reverse(path.begin(), path.end());
            allPaths.push_back(path);
            reverse(path.begin(), path.end());
            path.pop_back();
            return;
        }
        path.push_back(node);
        for (int par : parent[node]) {
            dfs(par, S, parent, path, allPaths);
        }
        path.pop_back();
    }

    // Function to restore all paths from source S to target T
    vector<vector<int>> restore_all_paths(int S, int T, vector<vector<int>>& parent) {
        vector<vector<int>> allPaths;
        vector<int> path;
        dfs(T, S, parent, path, allPaths);
        return allPaths;
    }
};

int main() {
    int V = 5;  // Number of vertices
    vector<vector<int>> adj[V];  // Graph represented as an adjacency list
    adj[0].push_back({1, 2});
    adj[0].push_back({4, 1});
    adj[1].push_back({2, 3});
    adj[2].push_back({3, 6});
    adj[4].push_back({2, 2});
    adj[4].push_back({5, 4});
    adj[5].push_back({3, 1});

    int S = 0;  // Source node
    int T = 3;  // Target node

    Solution sol;
    vector<vector<int>> parent(V);  // To store parents for path restoration
    vector<int> dist = sol.dijkstra(V, adj, S, parent);  // Run Dijkstra to find shortest paths

    vector<vector<int>> allPaths = sol.restore_all_paths(S, T, parent);  // Find all shortest paths from S to T

    // Print all shortest paths
    for (const auto& path : allPaths) {
        for (int node : path) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}

