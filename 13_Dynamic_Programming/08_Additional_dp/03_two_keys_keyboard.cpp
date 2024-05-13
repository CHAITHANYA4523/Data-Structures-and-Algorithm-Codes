class Solution {
public:
    int minSteps(int n) {
        int current = 1;
        int copied = 0;
        int count = 0;
        while(current < n){
            int rest = n-current;
            if(rest % current == 0){
                copied = current;
                current = 2*current;
                //copy and paste operation
                count = count + 2;
            }
            else{
                current = current + copied;
                count++;
            }
        }
        return count;
    }
};

class Solution {
private:
    bool flag = true;
    int minOperations(int charOnScreen, int paste, int n, vector<vector<int>> &dp){
        if(charOnScreen == n) return 0;
        if(charOnScreen > n) return 1e9;
        if(dp[charOnScreen][paste] != -1) return dp[charOnScreen][paste];
        int copyOperation = minOperations(2*charOnScreen, charOnScreen, n, dp);
        int pasteOperation = minOperations(charOnScreen+paste, paste, n, dp);
        return dp[charOnScreen][paste] = 1 + min(1 + copyOperation, pasteOperation);
    }
public:
    int minSteps(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        if(n == 1) return 0;
        return minOperations(1, 1, n, dp)+1;
    }
};