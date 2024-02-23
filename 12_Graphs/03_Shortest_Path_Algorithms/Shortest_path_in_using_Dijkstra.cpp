#include <bits/stdc++.h>
#include<iterator>
using namespace std;


void innit_code(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif // ONLINE_JUDGE
}
void dijkstra(vector<vector<long long>> &edges, long long start, long long end){
	vector<pair<long,long>> adj[end+1];
	for(auto it:edges){
		adj[it[0]].push_back({it[1], it[2]});
		adj[it[1]].push_back({it[0], it[2]});
	}
	vector<long long> dist(end+1, 1e18), parent(end+1, -1);
	dist[1] = 0;
	priority_queue<pair<long,long>, vector<pair<long,long>>, greater<pair<long,long>>> pq;
	//{distance, node}
	pq.push({0, start});
	while(!pq.empty()){
		long long distance = pq.top().first;
		long long node = pq.top().second;
		pq.pop();
		for(auto it:adj[node]){
			long long adjNode = it.first;
			long long edgeW = it.second;
			if(distance+edgeW < dist[adjNode]){
				dist[adjNode] = distance+edgeW;
				parent[adjNode] = node;
				pq.push({dist[adjNode], adjNode});
			}
		}
	}
    //if target is not reachable
	if(dist[end] == 1e18) cout << -1 ;
    //if target is reachable
	else{
		vector<long long> path;
		for(long long v = end; v != -1; v = parent[v]){
			path.push_back(v);
		}
		reverse(path.begin(), path.end());
		for(auto it:path) cout << it << " ";
	}
}
int main() {
	innit_code();
	long long n, m;
	cin >> n >> m;
	vector<vector<long long>> v(m, vector<long long>(3));
	for(long long i=0; i<m; i++){
		cin >> v[i][0];
		cin >> v[i][1];
		cin >> v[i][2];
	}
    dijkstra(v, 1, n);
    return 0;
}