//Approach
//sort the strings in the vector with respect to their lengths
//compare strings with their lengths and check whether the longest commmon subsequence is equal to the minimum length string as the difference between current string and predecessor string is only one character.

class Solution {
private:
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
    
    static bool compareLength(string &s1, string &s2){
        return s1.length() < s2.length();
    }

public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        if(n == 1) return 1;
        sort(words.begin(), words.end(), compareLength);
        vector<int> dp(n,1);
        vector<int> hash(n);
        int maxi = INT_MIN;
        for(int i=1; i<=n-1; i++){
            for(int j = 0; j <=i-1; j ++){
                int bigStrLen = words[i].length();
                int smallStrLen = words[j].length();
                if(bigStrLen == smallStrLen + 1){
                    if(smallStrLen ==  longestCommonSubsequence(words[i], words[j]) && dp[i] < dp[j] + 1){
                        dp[i] = 1 + dp[j];
                    }
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};

class Solution {
private:
    bool compare(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        if(n != m+1) return false;
        int first = 0;
        int second = 0;
        while(first < s1.size()){
            if(second < s2.size() && s1[first] == s2[second]){
                first++;
                second++;
            }
            else{
                first++;
            }
        }
        if(first == s1.size() && second == s2.size()) return true;
        return false;
    }
    
    static bool compareLength(string &s1, string &s2){
        return s1.length() < s2.length();
    }

public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        if(n == 1) return 1;
        sort(words.begin(), words.end(), compareLength);
        vector<int> dp(n,1);
        vector<int> hash(n);
        int maxi = INT_MIN;
        for(int i=1; i<=n-1; i++){
            for(int j = 0; j <=i-1; j ++){
                if(compare(words[i], words[j]) && dp[i] < dp[j] + 1){
                    dp[i] = 1 + dp[j];
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};
