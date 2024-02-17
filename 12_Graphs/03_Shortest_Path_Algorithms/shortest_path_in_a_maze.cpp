class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1) return -1;
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        dist[0][0] = 1;
        vector<vector<int>> visited(n, vector<int>(n, 0));
        int rowPath[] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int colPath[] = {-1, 0, 1, 1, 1, 0, -1, -1};
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        //{distance, {row, col}}
        pq.push({1,{0,0}});
        while(!pq.empty()){
            int dis = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            for(int i=0; i<8; i++){
                int nrow = row + rowPath[i];
                int ncol = col + colPath[i];
                if(nrow < n && nrow >= 0 && ncol < n && ncol >= 0 && !visited[nrow][ncol]){
                    if(grid[nrow][ncol] == 0){
                        pq.push({dis+1, {nrow, ncol}});
                        if(dis+1 < dist[nrow][ncol]) dist[nrow][ncol] = dis+1;
                        visited[nrow][ncol] = 1;
                    }
                }
            }
        }
        int ans = dist[n-1][n-1];
        if(ans == 1e9) return -1;
        return ans;
    }
};

/*
**Time Complexity:**
- The priority queue can have at most n^2 elements in the worst case, as there are n^2 cells in the grid.
- For each cell, we perform a push operation into the priority queue which takes O(\log n) time.
- Therefore, the total time complexity is O(n^2 \log n).

**Space Complexity:**
- The `dist` and `visited` matrices each take O(n^2) space.
- The priority queue also takes O(n^2) space in the worst case.
- Therefore, the total space complexity is O(n^2). 

Please note that n is the dimension of the input grid. If the grid is not a square, then n would be the total number of cells in the grid. In that case, the time complexity would be O(n \log n) and the space complexity would be O(n).
*/