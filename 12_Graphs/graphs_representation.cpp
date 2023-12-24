//using adjacency matrix
#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	int adj[n+1][m+1]; // one based indexing for zero based indexing take adj[n][m]
	for(int i=0; i<m; i++){
		int u, v;
		cin >> u >> v;
		adj[u][v] = 1;
		adj[v][u] = 1;
	}
	//for weighted graph
	for(int i=0; i<m; i++){
		int u, v, weight;
		cin >> u >> v >> weight;
		adj[u][v] = weight;
		adj[v][u] = weight;
	}
	return 0;
}

//Space complexitiy is O(n^2)

//using adjacency list
int main(){
	int n;
	cin >> n;
	//adjacency list for undirected graph
	vector<int> adj[n+1]; // one based indexing for zero based indexing take adj[n][m]
	for(int i=0; i<n; i++){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	//for directed graph
	for(int i=0; i<n; i++){
		int u, v;
		// u-->v
		cin >> u >> v;
		adj[u].push_back(v);
	}
	return 0;
}

//Space complexity is O(2*Edges) for undirected graph

//Space complexity is O(E) for directed graph

// for weighted graph
int main(){
	int n;
	cin >> n;
	//adjacency list for undirected graph
	vector<pair<int,int>> adj[n+1]; // one based indexing for zero based indexing take adj[n][m]
	for(int i=0; i<n; i++){
		int u, v, weight;
		cin >> u >> v >> weight;
		adj[u].push_back({v,weight});
		adj[v].push_back({u,weight});
	}
	return 0;
}