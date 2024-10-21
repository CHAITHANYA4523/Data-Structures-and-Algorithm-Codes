class Solution {
private:
    unordered_map<int, int> mp;
    unordered_map<int, unordered_map<int, bool>> memo; 
    bool solve(vector<int> &stones, int idx, int k) {
        if (idx == stones.size() - 1) return true;
        if (memo[idx].find(k) != memo[idx].end()) return memo[idx][k]; 

        bool case1 = false, case2 = false, case3 = false;
        if (mp.find(stones[idx] + k) != mp.end() && k >= 1) {
            case1 = solve(stones, mp[stones[idx] + k], k);
        }
        if (mp.find(stones[idx] + (k - 1)) != mp.end() && k - 1 >= 1) {
            case2 = solve(stones, mp[stones[idx] + (k - 1)], k - 1);
        }
        if (mp.find(stones[idx] + (k + 1)) != mp.end()) {
            case3 = solve(stones, mp[stones[idx] + (k + 1)], k + 1);
        }

        return memo[idx][k] = case1 || case2 || case3; 
    }

public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        for (int i = 0; i < n; i++) mp[stones[i]] = i;
        if (stones[1] != 1) return false;
        return solve(stones, 1, 1);
    }
};
