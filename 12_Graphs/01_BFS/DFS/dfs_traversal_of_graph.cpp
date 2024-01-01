class solution{
public:
    void dfs(int node, vector<int> adj[], vector<int>& ls, vector<int>& visited){
        visited[node] = 1;
        ls.push_back(node);
        //traverse all it's neighbours
        for(auto it : adj[node]){
            if(!visited[it]) dfs(it, adj, ls, visited);
        }
    }

    vector<int> dfsOfGraph(int n, vector<int> adj[]) {
        vector<int> visited(n, 0);
        int start = 0;
        vector<int> ls;
        dfs(start, adj, ls, visited);
        return ls;
    }
};

/*
Time Complexity: For an undirected graph, O(N) + O(2E), For a directed graph, O(N) + O(E), Because for every node we are calling the recursive function once, the time taken is O(N) and 2E is for total degrees as we traverse for all adjacent nodes. (2E = total summation of degrees)

Space Complexity: O(3N) ~ O(N), Space for dfs stack space, visited array and an adjacency list.
*/