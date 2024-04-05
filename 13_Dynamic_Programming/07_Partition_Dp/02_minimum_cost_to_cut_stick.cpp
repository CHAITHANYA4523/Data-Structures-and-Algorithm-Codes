/*

*/
class Solution {
private:
    int findMinimumCost(int i, int j, vector<int> &cuts, vector<vector<int>> &dp) {
        // Base case: If i is greater than j, there are no cuts to consider.
        if (i > j) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int mini = INT_MAX;
        for (int ind=i; ind<=j; ind++) {
            // Calculate the cost for making a cut at position 'ind'.
            int ans = cuts[j+1] - cuts[i-1] +
                    findMinimumCost(i, ind-1, cuts, dp) +
                    findMinimumCost(ind+1, j, cuts, dp);
            mini = min(mini, ans);
        }
        return dp[i][j] = mini;
    }

public:
    int minCost(int n, vector<int>& cuts) {
        int m = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(m+1, vector<int>(m+1, -1));
        return findMinimumCost(1, m, cuts, dp);
    }
};


//Tabulation

class Solution {
// private:
//     int findMinimumCost(int i, int j, vector<int> &cuts, vector<vector<int>> &dp) {
//         // Base case: If i is greater than j, there are no cuts to consider.
//         if (i > j) {
//             return 0;
//         }
//         if (dp[i][j] != -1) {
//             return dp[i][j];
//         }
//         int mini = INT_MAX;
//         for (int ind=i; ind<=j; ind++) {
//             // Calculate the cost for making a cut at position 'ind'.
//             int ans = cuts[j+1] - cuts[i-1] +
//                     findMinimumCost(i, ind-1, cuts, dp) +
//                     findMinimumCost(ind+1, j, cuts, dp);
//             mini = min(mini, ans);
//         }
//         return dp[i][j] = mini;
//     }

public:
    int minCost(int n, vector<int>& cuts) {
        int m = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        //take m+2 for the case when i=m, ind+1 might go out of bounds
        vector<vector<int>> dp(m+2, vector<int>(m+2, 0));
        //i goes from m to 1 and j goes from 1 to m in tabulation(opposite of memoisation)
        for(int i=m; i>=1; i--){
            for(int j=1; j<=m; j++){
                if(i > j) continue;
                int mini = INT_MAX;
                for (int ind=i; ind<=j; ind++) {
                    // Calculate the cost for making a cut at position 'ind'.
                    int ans = cuts[j+1] - cuts[i-1] + dp[i][ind-1] + dp[ind+1][j];
                    mini = min(mini, ans);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][m];
    }
};