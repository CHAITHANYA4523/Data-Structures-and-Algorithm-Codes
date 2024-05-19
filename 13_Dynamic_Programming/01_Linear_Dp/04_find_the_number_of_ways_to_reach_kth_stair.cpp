class Solution {
private:
    unordered_map<string,int> dp;
    int solve(int i, int tar, int jump, bool flag) {
        if(i-tar > 1) return 0;
        string key = to_string(i) + " " + to_string(jump) +  " " + to_string(flag);
        if(dp.count(key)) return dp[key];
        int ans = 0;
        if(i == tar) ans+=1;
        if(flag == false && i != 0){
            ans += solve(i-1, tar, jump, true);
        }
        ans += solve(i+(1<<jump), tar, jump+1, false);
        return dp[key] = ans;
    }

public:
    int waysToReachStair(int k) {
        return solve(1, k, 0, false);
    }
};

