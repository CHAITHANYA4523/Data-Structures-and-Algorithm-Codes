//using DFS
class Solution {
private:
    bool dfs(int node, int col, vector<int>& color, vector<vector<int>>& graph) {
        color[node] = col;
        for (int it : graph[node]) {
            // if uncoloured
            if (color[it] == -1) {
                if (dfs(it, !col, color, graph) == false) return false;
            }
            // if previously coloured and have the same colour
            else if (color[it] == col) {
                return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        // Array to store the color of each node (-1: uncolored, 0: color 0, 1: color 1)
        vector<int> color(V, -1);
        // for connected components
        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                if (dfs(i, 0, color, graph) == false) return false;
            }
        }
        return true;
    }
};

/*
Time Complexity: O(V + 2E), Where V = Vertices, 2E is for total degrees as we traverse all adjacent nodes.

Space Complexity: O(3V) ~ O(V), Space for DFS stack space, colour array and an adjacency list.
*/

//using BFS
class Solution {
public:
    // Function to check if the given graph is bipartite using BFS
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, -1);
        for (int i = 0; i < V; ++i) {
            if (color[i] == -1) {
                // Start BFS from the current uncolored node
                queue<int> q;
                q.push(i);
                color[i] = 0;
                while (!q.empty()) {
                    // Process the front node in the queue
                    int node = q.front();
                    q.pop();
                    for (int it : graph[node]) {
                        if (color[it] == -1) {
                            // If neighbor is uncolored, color it with the opposite color and enqueue
                            color[it] = !color[node];
                            q.push(it);
                        } else if (color[it] == color[node]) {
                            // If neighbor has the same color, the graph is not bipartite
                            return false;
                        }
                    }
                }
            }
        }
        // If the algorithm completes for all connected components without conflicts, the graph is bipartite
        return true;
    }
};

/*
Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges.

Space Complexity: O(V), representing the space needed for the queue, color array, and other constant space requirements.
*/