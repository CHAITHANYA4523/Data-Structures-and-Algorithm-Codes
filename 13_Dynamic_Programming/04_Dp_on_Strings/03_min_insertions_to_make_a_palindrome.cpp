class Solution {
private:
    int memoisation(string &s, int low, int high, vector<vector<int>> &dp){
        if(low >= high){
            return 0;
        }
        if(dp[low][high] != -1) return dp[low][high];
        if(s[low] != s[high]){
            int first = 1 + memoisation(s, low, high-1, dp);
            int second = 1 + memoisation(s, low+1, high, dp);
            return dp[low][high] = min(first, second);
        }
        //when both match we don't need to add them to the steps
        else{
            return dp[low][high] = 0 + memoisation(s, low+1, high-1, dp);
        }
    }
public:
    int minInsertions(string s) {
        int  n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return memoisation(s, 0, n-1, dp);
    }
};