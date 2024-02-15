// intuition - the intuition is to figure out the nodes which are neither a part of a cycle nor connected to the cycle. Any node which is a part of a cycle or leads to the cycle through an incoming edge towards the cycle, cannot be a safe node. Apart from these types of nodes, every node is a safe node.

class Solution {
private:
    bool dfsCheck(int source, vector<int> &vis, vector<int> &pathVis, vector<int> &check, vector<vector<int>>& graph){
        vis[source] = 1; 
        pathVis[source] = 1;
        for(auto adjacentNode:graph[source]){
            if(!vis[adjacentNode]){ 
                if(dfsCheck(adjacentNode, vis, pathVis, check, graph) == true){
                    check[source] = 0;
                    return true; 
                }
            }
            else if(pathVis[adjacentNode] && vis[adjacentNode]){ 
                check[source] = 0;
                return true; 
            }
        }

        check[source] = 1; // After all adjacent nodes have been explored, mark the source node as safe (not part of a cycle).
        pathVis[source] = 0; 
        return false; 
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size(); 
        vector<int> vis(n, 0); 
        vector<int> pathVis(n, 0); 
        vector<int> safeNodes; 
        vector<int> check(n, 0); 

        for(int i=0; i<n; i++){
            if(!vis[i]){ 
                dfsCheck(i, vis, pathVis, check, graph); 
            }
        }
        // A node is considered safe if every possible path from that node leads to a terminal node (i.e., a node with no outgoing edges).
        for(int i=0; i<n; i++){
            if(check[i]) safeNodes.push_back(i);
        }
        return safeNodes; 
    }
};

/*
Time Complexity: O(V+E)+O(V), where V = no. of nodes and E = no. of edges. There can be at most V components. So, another O(V) time complexity.

Space Complexity: O(n)+O(n)+O(n)+O(n) for vis, pathVis, check, and safeNodes avoiding auxilary stack space
*/

//approach - here we store edges in reverse order and perform normal kahn's topo sort for indegrees

class Solution {
public:
	vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
		vector<int> adjRev[V];
		int indegree[V] = {0};
		for (int i = 0; i < V; i++) {
			// adjacentNode -> source
			// source -> adjacentNode
			for (auto adjacentNode : adj[i]) {
				adjRev[adjacentNode].push_back(i);
				indegree[i]++;
			}
		}
		queue<int> q;
		vector<int> safeNodes;
		for (int i = 0; i < V; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			safeNodes.push_back(node);
			for (auto it : adjRev[node]) {
				indegree[it]--;
				if (indegree[it] == 0) q.push(it);
			}
		}
		sort(safeNodes.begin(), safeNodes.end());
		return safeNodes;
	}
};

/*
Time Complexity: O(V+E)+O(N*logN), where V = no. of nodes and E = no. of edges. This is a simple BFS algorithm. Extra O(N*logN) for sorting the safeNodes array, where N is the number of safe nodes.

Space Complexity: O(N) + O(N) + O(N) ~ O(3N), O(N) for the indegree array, O(N) for the queue data structure used in BFS(where N = no.of nodes), and extra O(N) for the adjacency list to store the graph in a reversed order.
*/