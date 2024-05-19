class Solution {
public:
    int numTilings(int n) {
        vector<long long> dp(1001, 0);
        int M = 1e9+7;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;
        if(n <= 3) return dp[n];
        for(int i=4; i<=n; i++){
            dp[i] = 2*dp[i-1] + dp[i-3];
            dp[i] = dp[i]%M;
        }
        return dp[n];
    }
};

// when N==0, we need return 0, but in dp , we need make dp[0]=1 for easy to construct formula

// dp[n]=dp[n-1]+dp[n-2]+ 2*(dp[n-3]+...+d[0])
// =dp[n-1]+dp[n-2]+dp[n-3]+dp[n-3]+2*(dp[n-4]+...+d[0])
// =dp[n-1]+dp[n-3]+(dp[n-2]+dp[n-3]+2*(dp[n-4]+...+d[0]))
// =dp[n-1]+dp[n-3]+dp[n-1]
// =2*dp[n-1]+dp[n-3]