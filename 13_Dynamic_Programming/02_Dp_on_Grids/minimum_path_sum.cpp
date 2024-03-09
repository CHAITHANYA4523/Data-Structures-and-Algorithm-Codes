//Memoization

class Solution {
private:
    int minSum(vector<vector<int>>& grid, int row, int col, vector<vector<int>> &dp){
        if(row == 0 && col == 0){
            return dp[row][col] = grid[row][col];
        }
        if(row < 0 || col < 0) return 1e9;
        if(dp[row][col] != -1){
            return dp[row][col];
        }
        int left = grid[row][col] + minSum(grid, row-1, col, dp);
        int up = grid[row][col] + minSum(grid, row, col-1, dp);
        return dp[row][col] = min(left, up);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return minSum(grid, n-1, m-1, dp);   
    }
};
/*
Time Complexity: O(N*M)
Reason: At max, there will be N*M calls of recursion.

Space Complexity: O((M-1)+(N-1)) + O(N*M)
Reason: We are using a recursion stack space: O((M-1)+(N-1)), here (M-1)+(N-1) is the path length and an external DP Array of size ‘N*M’.
*/

//Tabulation

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int> (m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i == 0 && j == 0){
                    dp[i][j] = grid[i][j];
                    continue;
                }
                int left = 1e9, up = 1e9;
                if(i > 0){
                    left = grid[i][j] + dp[i-1][j];
                }
                if(j > 0){
                    up = grid[i][j] + dp[i][j-1];
                }
                dp[i][j] = min(up, left);
            }
        }
        return dp[n-1][m-1];
    }
};

/*
Time Complexity: O(N*M)
Reason: There are two nested loops

Space Complexity: O(N*M)
Reason: We are using an external array of size ‘N*M’’.
*/

//Space Optimisation
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> prev(m, 0);
        for(int i=0; i<n; i++){
            vector<int> curr(m, 0);
            for(int j=0; j<m; j++){
                if(i == 0 && j == 0){
                    curr[j] = grid[i][j];
                    continue;
                }
                int left = 1e9, up = 1e9;
                if(i > 0){
                    up = grid[i][j] + prev[j];
                }
                if(j > 0){
                    left = grid[i][j] + curr[j-1];
                }
                curr[j] = min(up, left);
            }
            prev = curr;
        }
        return prev[m-1];
    }
};

/*
Time Complexity: O(M*N)
Reason: There are two nested loops

Space Complexity: O(N)
Reason: We are using an external array of size ‘N’ to store only one row
*/