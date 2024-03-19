class Solution {
private:
    int memoisation(string &text1, string &text2, int ind1, int ind2, vector<vector<int>> &dp){
        //when any one string goes out of bounds return 0 (no matching)
        if(ind1 < 0 || ind2 < 0){
            return 0;
        }
        //overlapping case
        if(dp[ind1][ind2] != -1){
            return dp[ind1][ind2];
        }
        //if both characters are matching add to the subsequence
        if(text1[ind1] == text2[ind2]){
            return dp[ind1][ind2] = 1 + memoisation(text1, text2, ind1-1, ind2-1, dp);
        }
        //if not matching check for both cases
        //1 is not added as characters not matched
        return dp[ind1][ind2] = max(memoisation(text1, text2, ind1-1, ind2, dp),
        memoisation(text1, text2, ind1, ind2-1, dp));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return memoisation(text1, text2, n-1, m-1, dp);
    }
};

//Shifting of index (for easy conversion into tabulation)

class Solution {
private:
    int memoisation(string &text1, string &text2, int ind1, int ind2, vector<vector<int>> &dp){
        if(ind1 == 0 || ind2 == 0){
            return 0;
        }
        //overlapping case
        if(dp[ind1][ind2] != -1){
            return dp[ind1][ind2];
        }
        //if both characters are matching add to the subsequence

        //ind1-1 is compared with ind2-1 as shifting is done
        if(text1[ind1-1] == text2[ind2-1]){
            return dp[ind1][ind2] = 1 + memoisation(text1, text2, ind1-1, ind2-1, dp);
        }
        //if not matching check for both cases
        //1 is not added as characters not matched
        return dp[ind1][ind2] = max(memoisation(text1, text2, ind1-1, ind2, dp),
        memoisation(text1, text2, ind1, ind2-1, dp));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        //shifting of index
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        //shifting of index 
        return memoisation(text1, text2, n, m, dp);
    }
};

/*
Time Complexity: O(N*M)
Reason: There are N*M states therefore at max ‘N*M’ new problems will be solved.

Space Complexity: O(N*M) + O(N+M)
Reason: We are using an auxiliary recursion stack space(O(N+M)) (see the recursive tree, in the worst case, we will go till N+M calls at a time) and a 2D array ( O(N*M)).
*/


//Tabulation

// Shifting of index

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        //shifting of index
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        //this base case can be avoided as the dp is intialised with zeroes.
        for(int i=0; i<=n; i++) dp[i][0] = 0;
        for(int j=0; j<=m; j++) dp[0][j] = 0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                //to counter shifting case
                if(text1[i-1] == text2[j-1]){
                    //picked so , both indices are reduced
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                //not  matched so, check for both cases
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};

//Space optimisation

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        //shifting of index
        vector<int> prev(m+1, 0), curr(m+1, 0);
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                //to counter shifting case
                if(text1[i-1] == text2[j-1]){
                    //picked so , both indices are reduced
                    curr[j] = 1 + prev[j-1];
                }
                //not  matched so, check for both cases
                else{
                    curr[j] = max(prev[j], curr[j-1]);
                }
            }
            prev = curr;
        }
        return prev[m];
    }
};

