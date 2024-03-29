class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        int i = 0, j = 0, n = nums.size(), count = 0;
        long int prod = 1;
        while(j<n){
            prod *= nums[j];
            while(prod >= k && i<j){
                prod = prod/nums[i];
                i++;
            }
            if(prod < k) count += j-i+1;
            j++;
        }
        return count;
    }
};