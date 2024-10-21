class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> memo(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return solve(grid, memo, 0, 0, m - 1);
    }
    
private:
    int solve(vector<vector<int>>& grid, vector<vector<vector<int>>>& memo, int i, int j1, int j2) {
        int n = grid.size();
        int m = grid[0].size();
        
        if (i == n) return 0;
        
        if (memo[i][j1][j2] != -1) return memo[i][j1][j2];
        
        int maxCherries = 0;
        
        for (int dj1 = -1; dj1 <= 1; ++dj1) {
            for (int dj2 = -1; dj2 <= 1; ++dj2) {
                int nj1 = j1 + dj1;
                int nj2 = j2 + dj2;
                if (nj1 >= 0 && nj1 < m && nj2 >= 0 && nj2 < m) {
                    maxCherries = max(maxCherries, solve(grid, memo, i + 1, nj1, nj2));
                }
            }
        }
        
        int currentCherries = grid[i][j1];
        if (j1 != j2) currentCherries += grid[i][j2]; 
        
        memo[i][j1][j2] = maxCherries + currentCherries;
        
        return memo[i][j1][j2];
    }
};
