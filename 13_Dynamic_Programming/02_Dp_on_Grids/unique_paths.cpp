//Memoisation
class Solution {
private:
    int allPaths(int row, int col, vector<vector<int>> &dp){
        if(row == 0 && col == 0){
            return 1;
        }
        if(row < 0 || col < 0){
            return 0;
        }
        if(dp[row][col] != -1) return dp[row][col];
        int up = allPaths(row-1, col, dp);
        int left = allPaths(row, col-1, dp);
        return dp[row][col] = left + up;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return allPaths(m-1, n-1, dp);
    }
};

//Tabulation
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                //base case
                if(i == 0 && j == 0){   
                    dp[i][j] = 1;
                }
                else{
                    int up = 0;
                    //make sure i and j are within bounds
                    if(i > 0){
                        up = dp[i-1][j];
                    }
                    int left = 0;
                    if(j > 0){
                        left = dp[i][j-1];
                    }
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[m-1][n-1];
    }
};

//Space optimastion
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n, 0);
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                vector<int> curr(n, 0);
                //base case
                if(i == 0 && j == 0){   
                    curr[j] = 1;
                }
                else{
                    int up = 0;
                    //make sure i and j are within bounds
                    if(i > 0){
                        up = prev[j];
                    }
                    int left = 0;
                    if(j > 0){
                        left = curr[j-1];
                    }
                    curr[j] = up + left;
                }
            }
            prev = curr;
        }
        return prev[n-1];
    }
};