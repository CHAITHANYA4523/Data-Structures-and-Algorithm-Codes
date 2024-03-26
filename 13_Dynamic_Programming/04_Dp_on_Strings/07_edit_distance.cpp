/*
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
*/

class Solution {
private:
    int memoisation(string s1, string s2, int i, int j, vector<vector<int>> &dp){
        //if s1 is exhausted(s1 is empty "") we need size of s2 no of insertions to match
        if(i < 0) return j+1;
        //if s2 is exhausted(s2 is empty "") we need size of s1 no of deletions to match 
        if(j < 0) return i+1;
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j]){
            return dp[i][j] = memoisation(s1, s2, i-1, j-1, dp);
        }
        else{
            //if we insert same character in s1 they match and check for next character 
            //in s2 with the same character in s1 as they didn't match
            int insertOperation = 1 + memoisation(s1, s2, i, j-1, dp);
            //if we delete a character in s1 we compare next character in s1 with 
            //the same character in s2 as they didn't match
            int deleteOperation = 1 + memoisation(s1, s2, i-1, j, dp);
            //if we replace they both become equal so, move to next indices
            int replaceOperation = 1 + memoisation(s1, s2, i-1, j-1, dp);
            return dp[i][j] = min(insertOperation, min(deleteOperation, replaceOperation));
        }
    }
public:
    int minDistance(string word1, string word2){
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return memoisation(word1, word2, n-1, m-1, dp);
    }
};

class Solution {
private:
    int memoisation(string s1, string s2, int i, int j, vector<vector<int>> &dp){
        if(i == 0) return j; 
        if(j == 0) return i;
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i-1] == s2[j-1]){
            return dp[i][j] = memoisation(s1, s2, i-1, j-1, dp);
        }
        else{
            //if we insert same character in s1 they match and check for next character 
            //in s2 with the same character in s1 as they didn't match
            int insertOperation = 1 + memoisation(s1, s2, i, j-1, dp);
            //if we delete a character in s1 we compare next character in s1 with 
            //the same character in s2 as they didn't match
            int deleteOperation = 1 + memoisation(s1, s2, i-1, j, dp);
            //if we replace they both become equal so, move to next indices
            int replaceOperation = 1 + memoisation(s1, s2, i-1, j-1, dp);
            return dp[i][j] = min(insertOperation, min(deleteOperation, replaceOperation));
        }
    }
public:
    int minDistance(string word1, string word2){
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return memoisation(word1, word2, n, m, dp);
    }
};

//Tabulation
class Solution {
public:
    int minDistance(string word1, string word2){
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        //when j == 0
        //for every row the zero'th index value is row number itself
        for(int i=0; i<=n; i++) dp[i][0] = i;
        //when i == 0
        //for every column the value of jth column is column number itself. 
        for(int j=0; j<=m; j++) dp[0][j] = j;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    int insertOperation = 1 + dp[i][j-1];
                    int deleteOperation = 1 + dp[i-1][j];
                    int replaceOperation = 1 + dp[i-1][j-1];
                    dp[i][j] = min(insertOperation, min(deleteOperation, replaceOperation));
                }
            }
        }
        return dp[n][m];
    }
};

//space optimisation
class Solution {
public:
    int minDistance(string word1, string word2){
        int n = word1.size(), m = word2.size();
        vector<int> prev(m+1, 0), curr(m+1, 0);
        for(int j=0; j<=m; j++){
            prev[j] = j;
        }
        for(int i=1; i<=n; i++){
            //for every row the zero'th index value is the row number itself
            curr[0] = i; 
            for(int j=1; j<=m; j++){
                if(word1[i-1] == word2[j-1]){
                    curr[j] = prev[j-1];
                }
                else{
                    int insertOperation = 1 + curr[j-1];
                    int deleteOperation = 1 + prev[j];
                    int replaceOperation = 1 + prev[j-1];
                    curr[j] = min(insertOperation, min(deleteOperation, replaceOperation));
                }
            }
            prev = curr;
        }
        return prev[m];
    }
};