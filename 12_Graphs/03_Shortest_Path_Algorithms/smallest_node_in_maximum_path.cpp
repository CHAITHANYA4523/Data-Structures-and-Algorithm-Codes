#include <bits/stdc++.h> 
int pathWithMaxMinValue(vector<vector<int>> &arr){
	int n = arr.size();
	int m = arr[0].size();
	vector<vector<int>> visited(n, vector<int>(m, 0));
	visited[0][0] = 1;
	//maxHeap
	//{node, {row, col}}
	priority_queue<pair<int,pair<int,int>>> pq;
	pq.push({arr[0][0], {0, 0}});
	int rowPath[] = {-1,0,1,0};
	int colPath[] = {0,1,0,-1};
	int ans = INT_MAX;
	while(!pq.empty()){
		int node = pq.top().first;
		int row = pq.top().second.first;
		int col = pq.top().second.second;
		pq.pop();
		ans = min(ans, node);
		if(row == n-1 && col == m-1) return ans;
		for(int i=0; i<4; i++){
			int nrow = row + rowPath[i];
			int ncol = col + colPath[i];
			if(nrow < n && nrow >= 0 && ncol < m && ncol >= 0 && !visited[nrow][ncol]){
				visited[nrow][ncol] = 1;
				pq.push({arr[nrow][ncol], {nrow, ncol}});
			}
		}
	}
	return ans;
}

/*
Time Complexity: O(NM log(NM))
Each cell in the grid is visited once, so the complexity is proportional to the number of cells, NM.
For each cell, an operation (push or pop) is performed on the priority queue. These operations have a time complexity of log(K), where K is the number of elements in the queue. In the worst case, all NM cells are in the queue.

The space complexity is O(NM) due to the 2D visited array and the priority queue, which can contain all cells in the worst case.
*/