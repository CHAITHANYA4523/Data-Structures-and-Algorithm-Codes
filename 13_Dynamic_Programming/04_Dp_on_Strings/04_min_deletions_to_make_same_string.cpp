//Approach
//find longest common subsequence and subtract 2 times of it from the total lenght of strings this way we can get characters that are present in one string and not in the other
class Solution {
private:
    int longestCommonSubsequence(string &s1, string &s2, int ind1,
    int ind2, vector<vector<int>> &dp){
        if(ind1 < 0 || ind2 < 0){
            return 0;
        }
        if(dp[ind1][ind2] != -1){
            return dp[ind1][ind2];
        }
        if(s1[ind1] == s2[ind2]){
            return dp[ind1][ind2] = 1 + longestCommonSubsequence(s1, s2, ind1-1, ind2-1, dp);
        }
        else{
            return dp[ind1][ind2] = max(longestCommonSubsequence(s1, s2, ind1, ind2-1, dp),
            longestCommonSubsequence(s1, s2, ind1-1, ind2, dp));
        }
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int lcs = longestCommonSubsequence(word1, word2, n-1, m-1, dp);
        return n+m-2*lcs;
    }
};