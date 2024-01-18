/*
Topological sorting only exists in Directed Acyclic Graph (DAG). If the nodes of a graph are connected through directed edges and the graph does not contain a cycle, it is called a directed acyclic graph(DAG). 

The topological sorting of a directed acyclic graph is nothing but the linear ordering of vertices such that if there is an edge between node u and v(u -> v), node u appears before v in that ordering.

Now, let’s understand Why topological sort only exists in DAG:

Case 1 (If the edges are undirected): If there is an undirected edge between node u and v, it signifies that there is an edge from node u to v(u -> v) as well as there is an edge from node v to u(v -> u). But according to the definition of topological sorting, it is practically impossible to write such ordering where u appears before v and v appears before u simultaneously. So, it is only possible for directed edges.
Case 2(If the directed graph contains a cycle).

If we try to get topological sorting of this cyclic graph, for edge 1->2, node 1 must appear before 2, for edge 2->3, node 2 must appear before 3, and for edge 3->1, node 3 must appear before 1 in the linear ordering. But such ordering is not possible as there exists a cyclic dependency in the graph. Thereby, topological sorting is only possible for a directed acyclic graph.
Approach: 

We will be solving it using the DFS traversal technique.
The algorithm steps are as follows:

1.We must traverse all components of the graph.
2.Make sure to carry a visited array(all elements are initialized to 0) and a stack data structure, where we are going to store the nodes after completing the DFS call.
3.In the DFS call, first, the current node is marked as visited. Then DFS call is made for all its adjacent nodes.
4.After visiting all its adjacent nodes, DFS will backtrack to the previous node and meanwhile, the current node is pushed into the stack.
5.Finally, we will get the stack containing one of the topological sortings of the graph.

Note: Points to remember, that node will be marked as visited immediately after making the DFS call and before returning from the DFS call, the node will be pushed into the stack.
*/

class Solution{
private:
        void dfs(int vis[], int node, stack<int> &st, vector<int> adj[]){
            vis[node] = 1;
            for(auto it:adj[node]){
                if(!vis[it]){
                    dfs(vis, it, st, adj);
                }
            }
            st.push(node);
        }
public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    int vis[V] = {0};
	    stack<int> st;
	    for(int i=0; i<V; i++){
	        if(!vis[i]) dfs(vis, i, st, adj);
	    }
	    vector<int> ans;
	    while(!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	}
};

/*
Time Complexity: O(V+E)+O(V), where V = no. of nodes and E = no. of edges. There can be at most V components. So, another O(V) time complexity.

Space Complexity: O(2N) + O(N) ~ O(2N): O(2N) for the visited array and the stack carried during DFS calls and O(N) for recursive stack space, where N = no. of nodes.
*/

//Using Kahn's algorithm or BFS traversal

/*
The algorithm steps are as follows:

1.First, we will calculate the indegree of each node and store it in the indegree array. We can iterate through the given adj list, and simply for every node u->v, we can increase the indegree of v by 1 in the indegree array. 
2.Initially, there will be always at least a single node whose indegree is 0. So, we will push the node(s) with indegree 0 into the queue.
3.Then, we will pop a node from the queue including the node in our answer array, and for all its adjacent nodes, we will decrease the indegree of that node by one. For example, if node u that has been popped out from the queue has an edge towards node v(u->v), we will decrease indegree[v] by 1.
4.After that, if for any node the indegree becomes 0, we will push that node again into the queue.
5.We will repeat steps 3 and 4 until the queue is completely empty. Finally, completing the BFS we will get the linear ordering of the nodes in the answer array.
Let’s understand how to find the indegree(s):

By visiting the adjacency list, we can find out the indegrees for each node. For example, if node 3 is an adjacent node of node 2, we will just increase indegree[3] by 1 as the adjacency list suggests that node 3 has an incoming edge from node 2.
*/
class Solution{
    public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    int inDegree[V] = {0};
	    for(int i=0; i<V; i++){
	        for(auto it:adj[i]){
	            inDegree[it]++;
	        }
	    }
	    queue<int> q;
	    for(int i=0; i<V; i++){
	        if(inDegree[i] == 0){
	            q.push(i);
	        }
	    }
	    vector<int> topo;
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        topo.push_back(node);
	        for(auto it:adj[node]){
	            inDegree[it]--;
	            if(inDegree[it] == 0) q.push(it);
	        }
	    }
	    return topo;
	}
};

/*
Time Complexity: O(V+E), where V = no. of nodes and E = no. of edges. This is a simple BFS algorithm.

Space Complexity: O(N) + O(N) ~ O(2N), O(N) for the indegree array, and O(N) for the queue data structure used in BFS(where N = no.of nodes).
*/