/*Approach: the problem is similar to LIS try to find the maximum LIS and subtract it from the total size of the array and also ensure that difference between any two numbers in LIS has to greater than or equal to the distance distance between them so the numbers between them would fit to form LIS.
ex: {1,2,3,4,20,15,5,6,7} it LIS is not {1,2,3,4,5,6,7} as we cannot replace 20, 15 with any number greater than 4 and less than 5 so, LIS are {1,2,3,4,20} and {1,2,3,4,15} 
*/

class Solution{
    public:
    int min_operations(vector<int>& nums) {
        // Code here
        int n = nums.size();
        vector<int> dp(n, 1);
        int maxi = 1;
        for(int i=0; i<n; i++){
            for(int prev = 0; prev<i; prev++){
                if(nums[prev] < nums[i] && (nums[i]-nums[prev] >= i-prev)){
                    dp[i] = max(dp[i], dp[prev] + 1);
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return n-maxi;
    }
};