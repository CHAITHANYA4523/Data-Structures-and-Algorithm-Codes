class Solution {
private:
    int M = 1e9+7;
    int solve(vector<int> &arr, int i, int n, int k, vector<int> &dp){
        if(i == n) return 0;
        if(dp[i] != -1) return dp[i];
        int maxSum = INT_MIN;
        int maxi = INT_MIN;
        int len = 0;
        for(int j=i; j<i+k && j<n; j++){
            len++;
            maxi = max(maxi, arr[j]);
            int sum = ((len*maxi)%M + solve(arr, j+1, n, k, dp)%M)%M;
            maxSum = max(maxSum, sum);
        }
        return dp[i] = maxSum;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return solve(arr, 0, n, k, dp);
    }
};

class Solution {
private:
    int M = 1e9+7;
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1, 0);
        for(int i=n-1; i>=0; i--){
            int maxSum = INT_MIN;
            int maxi = INT_MIN;
            int len = 0;
            for(int j=i; j<i+k && j<n; j++){
                len++;
                maxi = max(maxi, arr[j]);
                int sum = ((len*maxi)%M + dp[j+1]%M)%M;
                maxSum = max(maxSum, sum);
            }
            dp[i] = maxSum;
        }
        return dp[0];
    }
};