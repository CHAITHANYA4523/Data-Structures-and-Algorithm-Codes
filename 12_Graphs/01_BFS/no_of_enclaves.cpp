class Solution {
private:
    void dfsBoundaryCheck(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis, int n, int m){
        vis[row][col] = 1;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        for(int i=0; i<4; i++){
            int nrow = drow[i] + row;
            int ncol = dcol[i] + col;
            if(nrow >=0 && nrow < n && ncol < m && ncol >=0){
                if(!vis[nrow][ncol] && grid[nrow][ncol] == 1){
                    dfsBoundaryCheck(nrow, ncol, grid, vis, n, m);
                }
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        //for 1'st and last column
        for(int i=0; i<n; i++){
            if(grid[i][0] == 1 && !vis[i][0]){
                dfsBoundaryCheck(i, 0, grid, vis, n, m);
            }
            if(grid[i][m-1] == 1 && !vis[i][m-1]){
                dfsBoundaryCheck(i, m-1, grid, vis, n, m);
            }
        }
        //for 1'st and last row
        for(int j=0; j<m; j++){
            if(grid[0][j] == 1 && !vis[0][j]){
                dfsBoundaryCheck(0, j, grid, vis, n, m);
            }
            if(grid[n-1][j] == 1 && !vis[n-1][j]){
                dfsBoundaryCheck(n-1, j, grid, vis, n, m);
            }
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    ans++;
                }
            }
        }
        return ans;
    }
};

/*
Time Complexity: O(N x M)

The DFS function will be called for each land node (i.e., grid cell with a value of 1). In the worst-case scenario, all the cells in the grid could be land. For each land node, we are traversing its 4 neighbors. Therefore, the time complexity is proportional to the number of cells in the grid, which is N x M.

Space Complexity: O(N x M)

The space complexity is dominated by the vis array, which has the same size as the input grid, i.e., N x M. In the worst-case scenario, the depth of the recursive call stack can also go up to N x M, contributing to the space complexity. Therefore, the overall space complexity is O(N x M).
*/