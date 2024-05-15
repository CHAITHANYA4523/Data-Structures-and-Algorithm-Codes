class Solution {
private:    
    int remainingSum(string a, int k){
        int sum = 0;
        for(int i=k; i>=0; i--){
            sum += a[i];
        }
        return sum;
    }
    int solve(string s1, string s2, int i, int j, vector<vector<int>> &dp){
        if(i < 0 && j < 0) return 0;
        if(i < 0 || j < 0){
            return (i < 0) ? remainingSum(s2, j) : remainingSum(s1, i);
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j]){
            return dp[i][j] = solve(s1, s2, i-1, j-1, dp);
        }
        else{
            int deleteS1 = int(s1[i]) + solve(s1, s2, i-1, j, dp);
            int deleteS2 = int(s2[j]) + solve(s1, s2, i, j-1, dp);
            return dp[i][j] = min(deleteS1, deleteS2);
        }
    }
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(s1, s2, n-1, m-1, dp);
    }
};



class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        for(int i=1; i<=n; i++){
            dp[i][0] = dp[i-1][0] + s1[i-1];
        }

        for(int j=1; j<=m; j++){
            dp[0][j] = dp[0][j-1] + s2[j-1];
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = min(s1[i-1] + dp[i-1][j], s2[j-1] + dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};

/*
Here’s what each part does:

1) for(int i=1; i<=n; i++){ dp[i][0] = dp[i-1][0] + s1[i-1]; } This loop is initializing the first column of the DP table. It’s calculating the cost of making string s1 equal to an empty string by deleting characters from s1. The cost of deleting a character is its ASCII value. So, dp[i][0] is the cost of deleting the first i characters from s1.

2) for(int j=1; j<=m; j++){ dp[0][j] = dp[0][j-1] + s2[j-1]; } Similarly, this loop is initializing the first row of the DP table. It’s calculating the cost of making string s2 equal to an empty string by deleting characters from s2. So, dp[0][j] is the cost of deleting the first j characters from s2.
*/


