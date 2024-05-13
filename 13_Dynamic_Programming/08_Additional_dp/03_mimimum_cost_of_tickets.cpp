class Solution {
private:
    int findIndex(vector<int> &days, int key){
        int low = 0, high = days.size()-1;
        int ans = days.size();
        while(low <= high){
            int mid = low + (high-low)/2;
            if(days[mid] <= key){
                ans = mid;
                low = mid+1;
            }
            else high = mid-1;
        }
        return ans + 1;
    }
    int solve(vector<int>& days, vector<int>& cost, vector<int> &dp, int idx){
        if(idx >= days.size()) return 0;
        if(dp[days[idx]] != -1) return dp[days[idx]];
        int oneDay = cost[0] + solve(days, cost, dp, idx+1);
        int fifteenDays = cost[1] + solve(days, cost, dp, findIndex(days, days[idx]+7-1));
        int thirtyDays = cost[2] + solve(days, cost, dp, findIndex(days, days[idx]+30-1));
        return dp[days[idx]] = min(oneDay, min(fifteenDays, thirtyDays));
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(367, -1);
        return solve(days, costs, dp, 0);

    }
};