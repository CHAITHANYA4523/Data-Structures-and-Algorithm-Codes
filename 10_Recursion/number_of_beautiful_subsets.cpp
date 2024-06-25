class Solution {
private:
    int solve(vector<int> &nums, unordered_map<int,int> mp, 
    int k, int idx){
        if(idx < 0){
            if(mp.size() > 0) return 1;
            return 0;
        }
        int result = solve(nums, mp, k, idx-1);
        if(!mp[nums[idx]+k] && !mp[nums[idx]-k]){
            mp[nums[idx]]++;
            result += solve(nums, mp, k, idx-1);
            mp[nums[idx]]--;
        }
        return result;
    }
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        solve(nums, mp, k, nums.size()-1);
    }
};



class Solution {
private:
    int solve(vector<pair<int, int>>& s, int n, int k, int i){
        if(i == n) return 1;
        int skip = solve(s, n, k, i+1);
        int take = (1 << s[i].second) - 1;
        if(i+1 < n && s[i+1].first - s[i].first == k){
            take *= solve(s, n, k, i+2);
        }
        else{
            take *= solve(s, n, k, i+1);
        }
        return skip + take;
    }
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int result = 1;
        map<int, map<int,int>> freq;
        for(int &x:nums){
            freq[x%k][x]++;
        }
        for(auto &f:freq){
            vector<pair<int,int>> s(f.second.begin(), f.second.end());
            result *= solve(s, s.size(), k , 0);
        }
        return result - 1;
    }
};

/*
Since map is sorted, it is implemented by Self Balancing BST. Insert operation is 
O(logn), it will take O(nlog⁡n) to make map. There can be kkk different remainders, meaning maximum kkk subset splits.
Worst case hits when remainder is same for all numbers (i.e., all comes in same subset subset 1) and no number is repeated (frequency=1frequency = 1frequency=1), time is still
O(2^n).

Time Complexity: O(nlog⁡n+2^n)=O(2^n)
Space Complexity: O(n+k)
*/

class Solution {
private:
    int solve(vector<pair<int, int>>& s, int n, int k, int i, vector<int> &count){
        if(i == n) return 1;
        if(count[i] != -1) return count[i];
        int skip = solve(s, n, k, i+1, count);
        int take = (1 << s[i].second) - 1;
        if(i+1 < n && s[i+1].first - s[i].first == k){
            take *= solve(s, n, k, i+2, count);
        }
        else{
            take *= solve(s, n, k, i+1, count);
        }
        return count[i] = skip + take;
    }
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int result = 1;
        map<int, map<int,int>> freq;
        for(int &x:nums){
            freq[x%k][x]++;
        }
        for(auto &f:freq){
            vector<pair<int,int>> s(f.second.begin(), f.second.end());
            vector<int> count(s.size(), -1);
            result *= solve(s, s.size(), k , 0, count);
        }
        return result - 1;
    }
};


/*
Making map is still O(nlogn). Calculating answer for one subset will be equal to number of states in DP which makes it O(n).

Time Complexity: O(nlog⁡n+n)==O(nlogn)
Space Complexity: O(n+k)
*/

class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int result = 1;
        map<int, map<int, int>> freq;
        for (int& x: nums) {
            freq[x % k][x]++;
        }
        for (auto& fr: freq) {
            int n = fr.second.size();
            vector<pair<int, int>> s(fr.second.begin(), fr.second.end());
            vector<int> count(n + 1);
            count[n] = 1;
            for (int i = n - 1; i >= 0; i--) {
                int skip = count[i + 1];
                int take = (1 << s[i].second) - 1;
                if (i + 1 < n && s[i + 1].first - s[i].first == k) {
                    take *= count[i + 2];
                } else {
                    take *= count[i + 1];
                }
                count[i] = skip + take;
            }
            result *= count[0];
        }
        return result - 1;
    }
};


/*
Time Complexity: O(nlogn)
Space Complexity: O(n+k)
*/


/*
To calculate f(i), we only need f(i+1) and f(i+2).
Storing f(i+3) onwards is useless.

curr=f(i)
next1=f(i+1)
next2=f(i+2)

*/

class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int result = 1;
        map<int, map<int, int>> freq;
        for (int& x: nums) {
            freq[x % k][x]++;
        }
        for (auto& fr: freq) {
            int n = fr.second.size(), curr, next1 = 1, next2;
            vector<pair<int, int>> s(fr.second.begin(), fr.second.end());
            for (int i = n - 1; i >= 0; i--) {
                int skip = next1;
                int take = (1 << s[i].second) - 1;
                if (i + 1 < n && s[i + 1].first - s[i].first == k) {
                    take *= next2;
                } else {
                    take *= next1;
                }
                curr = skip + take;
                next2 = next1; next1 = curr;
            }
            result *= curr;
        }
        return result - 1;
    }
};


