//Logic
// [[-10]]                     : ans  = 1 + (-(-10)) = 11 (explanation to first point mentioned)
// [[10]]                      : ans  = 1 as we still need 1 health at first place to get there (explanation to second point mentioned)
// [[-2,-3,3,-5,-10]]          : ans = 1 + (-(-17)) = 18 same as 1st case
// [[2,3,3,5,10]]              : ans = 1 same as 2nd test case, explanation to second point mentioned to asking question

//Memoisation
class Solution {
private:
    int findInitialHealth(vector<vector<int>>& dungeon, int row, int col, int n,
    int m, vector<vector<int>> &dp){
        if(row == n || col == m){
            return 1e9;
        }
        if(row == n-1 && col == m-1){
            return dungeon[row][col] > 0 ? 1 : 1 - dungeon[row][col];
        }
        if(dp[row][col] != -1){
            return dp[row][col];
        }
        int right = findInitialHealth(dungeon, row, col+1, n, m, dp);
        int down = findInitialHealth(dungeon, row+1, col, n, m, dp);
        /// min of either values and then cost of this cell
        int minHealthRequired =  min(right, down) - dungeon[row][col];
        return dp[row][col] = (minHealthRequired <= 0) ? 1 : minHealthRequired;
    }
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size(), m = dungeon[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return findInitialHealth(dungeon, 0, 0, n, m, dp);
    }
};

//Tabulation
int calculateMinimumHP(vector<vector<int> > &dungeon) {
    int n = dungeon.size();
    int m = dungeon[0].size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 1e9));
    dp[n][m-1] = 1;
    dp[n-1][m] = 1;
    for(int i=n-1; i>=0; i--){
        for(int j=m-1; j>=0; j--){
            int need = min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j];                
            // store this value
            dp[i][j] = need <= 0 ? 1 : need;
        }
    }
    return dp[0][0];
}