class Solution {
private:
    bool isPalindrome(string &temp, int start, int end){
        while(start <= end){
            if(temp[start] != temp[end]) return false;
            start++;
            end--;
        }
        return true;
    }
    int solve(string &s, int i, int n, vector<int> &dp){
        if(i == n) return 0;
        if(dp[i] != -1) return dp[i];
        int minCost = INT_MAX;
        for(int j=i; j<n; j++){
            if(isPalindrome(s, i, j)){
                int cost = 1 + solve(s, j+1, n, dp);
                minCost = min(cost, minCost);
            }
        }
        return dp[i] = minCost;
    }
public:
    int minCut(string s) {
        int n = s.length();
        if(isPalindrome(s, 0, n-1)) return 0; // Add this check
        vector<int> dp(n, -1);
        return solve(s, 0, n, dp) - 1;
    }
};


class Solution {
private:
    bool isPalindrome(string &temp, int start, int end){
        while(start <= end){
            if(temp[start] != temp[end]) return false;
            start++;
            end--;
        }
        return true;
    }
public:
    int minCut(string s) {
        int n = s.length();
        vector<int> dp(n+1, 0);
        for(int i=n-1; i>=0; i--){
            int minCost = INT_MAX;
            for(int j=i; j<n; j++){
                if(isPalindrome(s, i, j)){
                    int cost = 1 + dp[j+1];
                    minCost = min(cost, minCost);
                }
            }
            dp[i] = minCost;
        }
        return dp[0] - 1;
    }
};
