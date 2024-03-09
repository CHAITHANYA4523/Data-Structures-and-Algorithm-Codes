//Memoisation

// Function to find the minimum path sum recursively with memoization
int minimumPathSumUtil(int i, int j, vector<vector<int> > &triangle, int n, vector<vector<int> > &dp) {
    // If the result for this cell is already calculated, return it
    if (dp[i][j] != -1)
        return dp[i][j];
    // If we're at the bottom row, return the value of the current cell
    if (i == n - 1)
        return triangle[i][j];
    // Calculate the sum of two possible paths: going down and going diagonally
    int down = triangle[i][j] + minimumPathSumUtil(i + 1, j, triangle, n, dp);
    int diagonal = triangle[i][j] + minimumPathSumUtil(i + 1, j + 1, triangle, n, dp);
    // Store the minimum of the two paths in the dp table and return it
    return dp[i][j] = min(down, diagonal);
}

// Function to find the minimum path sum in the given triangle
int minimumPathSum(vector<vector<int> > &triangle, int n) {
    vector<vector<int> > dp(n, vector<int>(n, -1));
    return minimumPathSumUtil(0, 0, triangle, n, dp);
}

/*
Time Complexity: O(N*N)
Reason: There are two nested loops

Space Complexity: O(N*N)
Reason: We are using an external array of size ‘N*N’. The stack space will be eliminated.
*/

//Tabulation
int minimumPathSum(vector<vector<int> > &triangle, int n) {
    vector<vector<int> > dp(n, vector<int>(n, 0));
    for (int j = 0; j < n; j++) {
        dp[n - 1][j] = triangle[n - 1][j];
    }
    // Iterate through the triangle rows in reverse order
    for (int i = n - 2; i >= 0; i--) {
        for (int j = i; j >= 0; j--) {
            // Calculate the minimum path sum for the current cell
            int down = triangle[i][j] + dp[i + 1][j];
            int diagonal = triangle[i][j] + dp[i + 1][j + 1];
            // Store the minimum of the two possible paths in dp
            dp[i][j] = min(down, diagonal);
        }
    }
    // The top-left cell of dp now contains the minimum path sum
    return dp[0][0];
}

/*
Time Complexity: O(N*N)
Reason: There are two nested loops

Space Complexity: O(N*N)
Reason: We are using an external array of size ‘N*N’. The stack space will be eliminated.
*/

//Space optimisation
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size(), m = triangle[n-1].size();
        vector<int> next(m, 0);
        for(int i=0; i<m; i++){
            next[i] = triangle[n-1][i];
        }
        for(int i=n-2; i>=0; i--){
            int m = triangle[i].size();
            vector<int> curr(m, 0);
            for(int j=m-1; j>=0; j--){
                int downRight = triangle[i][j] + next[j+1];
                int down = triangle[i][j] + next[j];
                curr[j] = min(downRight, down);
            }
            next = curr;
        }
        return next[0];
    }
};

/*
Time Complexity: O(N*N)
Reason: There are two nested loops

Space Complexity: O(N)
Reason: We are using an external array of size ‘N’ to store only one row.
*/
