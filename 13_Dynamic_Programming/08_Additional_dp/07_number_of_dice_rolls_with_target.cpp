class Solution {
public:
    const int mod = (int)pow(10, 9) + 7; // Modulo value for calculations

    // Function to calculate the number of ways to obtain a target sum using 'n' dice rolls with 'k' faces on each die
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1)); // Create a 2D vector for memoization
        return recursion(dp, n, k, target); // Call the recursive function with memoization
    }

private:
    // Recursive function to calculate the number of ways to obtain the target sum
    int recursion(vector<vector<int>>& dp, int n, int k, int target) {
        // Base cases: if the target sum is reached with 'n' dice rolls or if 'n' becomes 0 or target reaches 0, return accordingly
        if (target == 0 && n == 0) return 1;
        if (n == 0 || target <= 0) return 0;

        // If the result is already computed, return the stored value from the memoization table
        if (dp[n][target] != -1) return dp[n][target] % mod;

        int ways = 0; // Variable to count the number of ways to obtain the target sum
        for (int i = 1; i <= k; i++) {
            // Calculate the number of ways by considering each possible face value of the die
            ways = (ways + recursion(dp, n - 1, k, target - i)) % mod;
        }
        dp[n][target] = ways % mod; // Store the computed result in the memoization table
        return dp[n][target];
    }
};





class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        int M = 1e9+7;
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
        dp[0][0] = 1; // Base case: 0 ways to roll 0 dice to achieve sum > 0

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= target; j++) {
                for(int x = 1; x <= k; x++) {
                    if(j >= x) {
                        dp[i][j] = (dp[i][j] + dp[i-1][j-x]) % M;
                    }
                }
            }
        }
        return dp[n][target];
    }
};
