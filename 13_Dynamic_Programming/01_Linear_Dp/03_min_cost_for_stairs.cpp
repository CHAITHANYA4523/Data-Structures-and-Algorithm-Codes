//Memoisation
class Solution {
private:
    int minCost(vector<int> &cost,  int n, vector<int> &dp){
        if(n == 0 || n == 1){
            return dp[n] = cost[n];
        } 
        //avoiding negative edge case when n-2 is called from index 1
        if(n < 0) return 0;
        if(dp[n] != -1) return dp[n];
        int twoStep = minCost(cost, n-2, dp);
        int oneStep = minCost(cost, n-1, dp);
        return dp[n] = cost[n] + min(twoStep, oneStep);
        
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, -1);
        return min(minCost(cost, n-1, dp), minCost(cost, n-2, dp));
    }
};

//tabulation
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, 0);
        int prev, prev2;
        for(int i=0; i<n; i++){
            if(i == 0 || i == 1){
                dp[i] = cost[i];
            }
            else{
                prev2 = dp[i-2];
                prev = dp[i-1];
                dp[i] = cost[i] + min(prev2, prev);
            }
        }
        return min(dp[n-1], dp[n-2]);
    }  

//space optimisation
class Solution{
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int prev = cost[1], prev2 = cost[0], curr;
        if(n == 2) return min(prev, prev2);
        for(int i=2; i<n; i++){
            curr = cost[i] + min(prev2, prev);
            prev2 = prev;
            prev = curr;
        }
        return min(prev, prev2);
    } 
};