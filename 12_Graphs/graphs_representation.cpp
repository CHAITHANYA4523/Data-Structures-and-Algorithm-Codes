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
	return 0;
}

