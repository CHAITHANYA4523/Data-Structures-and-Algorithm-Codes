//Approach
//smallest common supersequence = len(string1) len(string2) - len(longest common subsequence)
//find longest common subsequence (tabulation method) and create final ans from table
class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                //to counter shifting case
                if(s1[i-1] == s2[j-1]){
                    //picked so , both indices are reduced
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                //not  matched so, check for both cases
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        int len = dp[n][m];
        int i = n, j = m;
        string ans = "";
        //shifting is done so , i > 0 and j > 0
        while(i>0 && j>0){
            if(s1[i-1] == s2[j-1]){
                ans.push_back(s1[i-1]);
                i--;
                j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]){
                //as we don't come to this row again add it to the ans.
                ans.push_back(s1[i-1]);
                i--;
            }
            else{
                //as we don't come to this row again add it to the ans.
                ans.push_back(s2[j-1]);
                j--;
            }
        }
        //to counter cases where one string bigger than the other
        while(i>0){
            ans.push_back(s1[i-1]);
            i--;
        }
        while(j>0){
            ans.push_back(s2[j-1]);
            j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


