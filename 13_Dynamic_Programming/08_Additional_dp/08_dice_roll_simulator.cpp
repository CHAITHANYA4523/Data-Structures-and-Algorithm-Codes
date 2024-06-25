class Solution {
private:
    int M = 1e9 + 7;
    int solve(int n, vector<int> rollMax, vector<vector<vector<int>>> &dp, int last, int cnt){
        if(n == 0) return 1;
        if(dp[n][last][cnt] != -1) return dp[n][last][cnt];
        int ways = 0;
        for(int i=1; i<=6; i++){
            if(i == last){
                if(cnt + 1 <= rollMax[i-1]){
                    ways = (ways%M + solve(n-1, rollMax, dp, last, cnt+1)%M) % M;
                }
            }
            else{
                ways = (ways%M + solve(n-1, rollMax, dp, i, 1)%M) % M;
            }
        }
        return dp[n][last][cnt] = ways % M;
    }
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(7, vector<int>(16, -1)));
        return solve(n, rollMax, dp, 0, 0);
    }

};

