//Approach: sort the given array and solve for longest increasing divisible subsequence

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        //sort the array and modify the question to LIS
        //in sorted sequence if [1,4,8] if 8%4 == 0 then 4%1 == 0
        sort(nums.begin(), nums.end());
        vector<int> hash(n);
        vector<int> dp(n, 1);
        for(int i=1; i<n; i++){
            hash[i] = i;
            for(int j=0; j<i; j++){
                if(nums[i]%nums[j] == 0 && dp[i] < 1 + dp[j]){
                    dp[i] = 1 + dp[j];
                    hash[i] = j;
                }
            }
        }
        int lastIndex = -1;
        int maxi = INT_MIN;
        for(int i=0; i<n; i++){
            if(dp[i] > maxi){
                maxi = dp[i];
                lastIndex = i;
            }
        }
        vector<int> temp;
        temp.push_back(nums[lastIndex]);
        while(hash[lastIndex] != lastIndex){
            lastIndex = hash[lastIndex];
            temp.push_back(nums[lastIndex]);
        }
        return temp;
    }
};

/*
Time Complexity: O(N*N)
Reason: There are two nested loops.

Space Complexity: O(N)
Reason: We are only using two rows of size n.
*/