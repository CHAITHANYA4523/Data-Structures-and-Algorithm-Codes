class Solution {
private:    
    int drow[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int dcol[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
    
    double solve(vector<vector<vector<double>>> &dp, int k, int n, int row, int col){
        if(row < 0 || row >= n || col < 0 || col >= n) return 0.0;
        if(k == 0) return 1.0;
        if(dp[k][row][col] != -1.0) return dp[k][row][col];
        
        dp[k][row][col] = 0.0;
        for(int i = 0; i < 8; i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            dp[k][row][col] += solve(dp, k - 1, n, nrow, ncol) / 8.0;
        }
        return dp[k][row][col];
    }
    
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(k+1, vector<vector<double>>(n, vector<double>(n, -1.0)));
        return solve(dp, k, n, row, column);
    }
};


class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        // Directions a knight can move
        vector<int> dRow = {-2, -2, -1, -1, 1, 1, 2, 2};
        vector<int> dCol = {-1, 1, -2, 2, -2, 2, -1, 1};
        
        // 3D DP array initialization
        vector<vector<vector<double>>> dp(k+1, vector<vector<double>>(n, vector<double>(n, 0.0)));
        
        // Base case: After 0 moves, the knight is on the board with probability 1
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                dp[0][r][c] = 1.0;
            }
        }
        
        // Bottom-up DP
        for (int step = 1; step <= k; ++step) {
            for (int r = 0; r < n; ++r) {
                for (int c = 0; c < n; ++c) {
                    for (int move = 0; move < 8; ++move) {
                        int nr = r + dRow[move];
                        int nc = c + dCol[move];
                        if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                            dp[step][r][c] += dp[step - 1][nr][nc] / 8.0;
                        }
                    }
                }
            }
        }
        
        // The final probability is the value in the DP table after k moves from the starting position
        return dp[k][row][column];
    }
};
