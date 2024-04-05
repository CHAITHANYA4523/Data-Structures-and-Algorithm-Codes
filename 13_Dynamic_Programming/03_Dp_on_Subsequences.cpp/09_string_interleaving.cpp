//memoisation
//memory limit exceeded in leetcode

class Solution {
private:
    bool checkInterLeave(string s1, string s2, string s3, int i, int j, int k, vector<vector<bool>> &dp) {
        if (k == s3.size()) {
            return (i == s1.size() && j == s2.size());
        }
        if(dp[i][j] != false) return dp[i][j];
        bool valid1 = false, valid2 = false;
        if (i < s1.size() && s1[i] == s3[k]) {
            valid1 = checkInterLeave(s1, s2, s3, i+1, j, k+1, dp);
        }
        if (j < s2.size() && s2[j] == s3[k]) {
            valid2 = checkInterLeave(s1, s2, s3, i, j+1, k+1, dp);
        }
        return dp[i][j] = valid1 || valid2;
    }

public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()) return false;
        int n = s1.size(), m = s2.size();
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
        return checkInterLeave(s1, s2, s3, 0, 0, 0, dp);
    }
};

//Tabulation
class Solution{
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size();
        if (n + m != s3.size()) return false;
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        // Base case: empty strings can form an empty string
        dp[n][m] = true;
        for (int i = n; i >= 0; --i){
            for (int j = m; j >= 0; --j){
                if (i < n && s1[i] == s3[i+j]){
                    dp[i][j] = dp[i][j] || dp[i+1][j];
                }
                if (j < m && s2[j] == s3[i+j]){
                    dp[i][j] = dp[i][j] || dp[i][j+1];
                }
            }
        }
        return dp[0][0];
    }
};