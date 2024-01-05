class Solution{
    private: 
        void dfs(vector<vector<int>>& vis, vector<vector<int>>& grid, int row, int col, int n, int m, vector<pair<int,int>> &v, int baseRow, int baseCol){
            vis[row][col] = 1;
            int first = row-baseRow;
            int second = col-baseCol;
            v.push_back({first, second});
            int delrow[] = {-1, 0, +1, 0};
            int delcol[] = {0, 1, 0, -1}; 
            for(int i=0; i<4; i++){
                int nrow = delrow[i]+row;
                int ncol = delcol[i]+col;
                if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m){ 
                    if(grid[nrow][ncol] == 1 && !vis[nrow][ncol]){
                        dfs(vis, grid, nrow, ncol, n, m, v, baseRow, baseCol); 
                    }
                }
            }
        }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        set<vector<pair<int,int>>> s;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    vector<pair<int,int>> v;
                    dfs(vis, grid, i, j, n, m, v, i, j);
                    s.insert(v);
                }
            }
        }
        return s.size();
    }
};

/*
Time Complexity: O(n*m)
The time complexity is determined by the number of cells in the grid that the algorithm needs to visit. In the worst-case scenario, the algorithm will need to visit every cell in the grid once. Since there are nm cells in the grid, the time complexity is O(nm).

Space Complexity: O(n*m)
The space complexity is determined by the maximum amount of space required by the algorithm. In this case, the space complexity is also O(n*m) because of the following reasons:

The vis vector, which keeps track of visited cells, requires n*m space.
In the worst-case scenario, the v vector, which stores the relative positions of the cells in an island, could potentially store all the cells in the grid. Therefore, it also requires n*m space.
The recursion stack of the DFS function could also potentially go as deep as n*m in the worst-case scenario (though this is highly unlikely in practice for a grid traversal problem).
*/