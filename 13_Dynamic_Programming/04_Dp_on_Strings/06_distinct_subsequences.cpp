class Solution {
// Function to count the number of distinct subsequences of s2 in s1
private: 
    int countUtil(string s1, string s2, int ind1, int ind2, vector<vector<int>>& dp) {
        // If s2 has been completely matched, return 1 (found a valid subsequence)
        if (ind2 < 0)
            return 1;
        // If s1 has been completely traversed but s2 hasn't, return 0
        if (ind1 < 0)
            return 0;
        // If the result for this state has already been calculated, return it
        if (dp[ind1][ind2] != -1)
            return dp[ind1][ind2];

        int result = 0;
        // If the characters match, consider two options: either leave one character in s1 and s2
        // or leave one character in s1 and continue matching s2
        if (s1[ind1] == s2[ind2]) {
            int leaveOne = countUtil(s1, s2, ind1 - 1, ind2 - 1, dp);
            int stay = countUtil(s1, s2, ind1 - 1, ind2, dp);
            result = (leaveOne + stay) % prime;
        } else {
            // If characters don't match, just leave one character in s1 and continue matching s2
            result = countUtil(s1, s2, ind1 - 1, ind2, dp);
        }
        // Store the result and return it
        dp[ind1][ind2] = result;
        return result;
    }
public:
    int numDistinct(string s, string t) {
        int n = s.length(), m = t.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return countUtil(s, t, n-1, m-1, dp);
    }
};

//Tabulation

//shifting of index is done to counter negative indexing

class Solution {
// private:
//     int memoisation(string s, string t, int i, int j, vector<vector<int>> &dp){
//         //base case
//         if(j < 0) return 1;
//         if(i < 0) return 0;
//         if(dp[i][j] != -1) return dp[i][j];
//         if(s[i] == t[j]){
//             return dp[i][j] = memoisation(s, t, i-1, j-1, dp) + memoisation(s, t, i-1, j, dp);
//         }
//         else{
//             return dp[i][j] = memoisation(s, t, i-1, j, dp);
//         }
//     }
public:
    int numDistinct(string s, string t) {
        int n = s.length(), m = t.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        //base case
        for(int i=0; i<=n; i++) dp[i][0] = 1;
        int MOD = 1e9 + 7;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%MOD;
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][m];
    }
};

//space optimastion using two arrays
class Solution {
// private:
//     int memoisation(string s, string t, int i, int j, vector<vector<int>> &dp){
//         //base case
//         if(j < 0) return 1;
//         if(i < 0) return 0;
//         if(dp[i][j] != -1) return dp[i][j];
//         if(s[i] == t[j]){
//             return dp[i][j] = memoisation(s, t, i-1, j-1, dp) + memoisation(s, t, i-1, j, dp);
//         }
//         else{
//             return dp[i][j] = memoisation(s, t, i-1, j, dp);
//         }
//     }
public:
    int numDistinct(string s, string t) {
        int n = s.length(), m = t.length();
        vector<int> prev(m+1, 0), curr(m+1);
        //base case
        prev[0] = 1;
        curr[0] = 1;
        int MOD = 1e9 + 7;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s[i-1] == t[j-1]){
                    curr[j] = (prev[j-1] + prev[j])%MOD;
                }
                else{
                    curr[j] = prev[j];
                }
            }
            prev = curr;
        }
        return prev[m];
    }
};


//space optimisation using only one array
//as we only require prev[j] and prev[j-1] we don't need curr array if computed from back

class Solution {
// private:
//     int memoisation(string s, string t, int i, int j, vector<vector<int>> &dp){
//         //base case
//         if(j < 0) return 1;
//         if(i < 0) return 0;
//         if(dp[i][j] != -1) return dp[i][j];
//         if(s[i] == t[j]){
//             return dp[i][j] = memoisation(s, t, i-1, j-1, dp) + memoisation(s, t, i-1, j, dp);
//         }
//         else{
//             return dp[i][j] = memoisation(s, t, i-1, j, dp);
//         }
//     }
public:
    int numDistinct(string s, string t) {
        int n = s.length(), m = t.length();
        vector<int> prev(m+1, 0);
        //base case
        prev[0] = 1;
        int MOD = 1e9 + 7;
        for(int i=1; i<=n; i++){
            for(int j=m; j>=1; j--){
                if(s[i-1] == t[j-1]){
                    prev[j] = (prev[j-1] + prev[j])%MOD;
                }
            }
        }
        return prev[m];
    }
};