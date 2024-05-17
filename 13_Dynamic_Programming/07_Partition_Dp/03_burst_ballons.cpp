//Approach 
/*
Note: The intuition is to first find the last balloon, then the second last, and so on. This is the sequence we need to follow to solve this problem.
*/

class Solution {
private:
    int findMaxCoins(vector<int> &nums, int i, int j, vector<vector<int>> &dp){
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int maxi = INT_MIN;
        for(int idx=i; idx<=j; idx++){
            int coins = nums[i-1]*nums[idx]*nums[j+1] + 
                        findMaxCoins(nums, i, idx-1, dp) +
                        findMaxCoins(nums, idx+1, j, dp);
            maxi = max(maxi, coins);
        }
        return dp[i][j] = maxi;
    }
public:
    int maxCoins(vector<int>& nums) {
        int m = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        vector<vector<int>> dp(m+1, vector<int>(m+1, -1));
        return findMaxCoins(nums, 1, m, dp);
    }
};

class Solution {
public:
    int maxCoins(vector<int> &nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        for (int i=n; i>=1; i--){
            for (int j=1; j<=n; j++){
                if (i > j) continue;
                int maxi = INT_MIN;
                for (int ind=i; ind<=j; ind++) {
                    int coins = nums[i-1] * nums[ind] * nums[j+1];
                    int remainingCoins = dp[i][ind-1] + dp[ind+1][j];
                    maxi = max(maxi, coins + remainingCoins);
                }
                dp[i][j] = maxi;
            }
        }
        return dp[1][n];
    }
};