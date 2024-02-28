class Solution{
    public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]){
       priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
       vector<int> visited(V, 0);
       int sum = 0;
       //{weight, node} 
       pq.push({0, 0});
       //E log(E) + E log(E)
       //E log(E)
       while(!pq.empty()){
           int wt = pq.top().first;
           int node = pq.top().second;
           // log(E)
           pq.pop();
           if(visited[node]) continue; 
           //mark visited and add the weight to resultant sum
            visited[node] = 1;
            sum += wt;
            //now check for adjacent nodes that are not visited and 
            //push them in to priority queue
            //E log(E)
            for(auto it:adj[node]){
                int adjNode = it[0];
                int edgeW = it[1];
                if(!visited[adjNode]){
                    pq.push({edgeW, adjNode});
                }
            }
       }
       return sum;
       
    }
};

/*
Time Complexity: O(E*logE) + O(E*logE)~ O(E*logE), where E = no. of given edges.
The maximum size of the priority queue can be E so after at most E iterations the priority queue will be empty and the loop will end. Inside the loop, there is a pop operation that will take logE time. This will result in the first O(E*logE) time complexity. Now, inside that loop, for every node, we need to traverse all its adjacent nodes where the number of nodes can be at most E. If we find any node unvisited, we will perform a push operation and for that, we need a logE time complexity. So this will result in the second O(E*logE). 

Space Complexity: O(E) + O(V), where E = no. of edges and V = no. of vertices. O(E) occurs due to the size of the priority queue and O(V) due to the visited array. If we wish to get the mst, we need an extra O(V-1) space to store the edges of the most.
*/

/*
Notes:
 in minimum spanning trees case even if we push the edge into pq , there's no sureity that the edge will be added to the mst. When prims algo ends there are still a few non accepted edges present in the pq hence we only mark it visited once its picked up from pq
*/

//for storing minimum spanning trees 
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	int spanningTree(int V, vector<vector<int>> adj[])
	{
		priority_queue<pair<int, pair<int,int>>,
		               vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;

		vector<int> vis(V, 0);
		// {wt, {node, parent}}
		vector<pair<int,int>> minSpanTree;
		pq.push({0, {0,-1}});
		int sum = 0;
		while (!pq.empty()) {
			auto it = pq.top();
			pq.pop();
			int node = it.second.first;
			int parentNode = it.second.second;
			int wt = it.first;

			if (vis[node] == 1) continue;
			// add it to the mst
			vis[node] = 1;
			sum += wt;
            //avoid adding -1 which added initially (not present in the graph)
			if(parentNode != -1) minSpanTree.push_back({parentNode, node});
			for (auto it : adj[node]) {
				int adjNode = it[0];
				int edW = it[1];
				if (!vis[adjNode]) {
					pq.push({edW, {adjNode, node}});
				}
			}
		}
		for(auto it:minSpanTree){
		    cout << "(" << it.first << " " << it.second << ") ";
		}
		cout << endl;
		return sum;
	}
};


int main() {

	int V = 5;
	vector<vector<int>> edges = {{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};
	vector<vector<int>> adj[V];
	for (auto it : edges) {
		vector<int> tmp(2);
		tmp[0] = it[1];
		tmp[1] = it[2];
		adj[it[0]].push_back(tmp);

		tmp[0] = it[0];
		tmp[1] = it[2];
		adj[it[1]].push_back(tmp);
	}

	Solution obj;
	int sum = obj.spanningTree(V, adj);
	cout << "The sum of all the edge weights: " << sum << endl;

	return 0;
}