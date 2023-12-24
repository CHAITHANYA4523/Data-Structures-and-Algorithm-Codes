class Solution{
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int n, vector<int> adj[]) {
        vector<int> bfs;
        int visited[n] = {0};
        //mark 0 as visited
        visited[0] = 1;
        queue<int> q;
        // zero based indexing
        q.push(0);
        while(!q.empty()){
            int vertex = q.front();
            q.pop();
            bfs.push_back(vertex);
            // it will traverse vector of adjacent nodes 
            for(auto it : adj[vertex]){
                //if vertex is not visited mark visited and push into queue
                if(!visited[it]){
                    visited[it] = 1;
                    q.push(it);
                }
            }
        }
        return bfs;
    }
};

/*
Time Complexity
Vertices (V): In BFS, you start from a source node and visit all of its adjacent nodes before moving on to the nodes adjacent to the starting node. This process continues until all nodes have been visited. Therefore, in the worst-case scenario, you will visit all the vertices in the graph once. This contributes O(V)
to the time complexity.

Edges (E): For each node, you also explore all the edges connected to it (to find its adjacent nodes). In the worst-case scenario, each edge will be looked at exactly once when it is removed from the adjacency list of its corresponding node. This contributes O(E) to the time complexity.

So, the total time complexity of the BFS algorithm is O(V+E)

Space Complexity
The space complexity of the Breadth-First Search (BFS) algorithm is O(V), where V
is the number of vertices in the graph. This is because, in the worst-case scenario, all vertices could be in the queue at the same time. Additionally, a separate space is needed to hold the ‘visited’ status of each vertex, which also takes O(V) space. Therefore, the total space complexity is O(V)
*/