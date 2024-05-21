class Solution {
private:
    int maxElement(vector<int> &nums){
        int maxi = INT_MIN;
        for(auto it:nums) maxi = max(maxi, it);
        return maxi;
    }
    long long summation(vector<int> &nums){
        long long sum = 0;
        for(auto it:nums) sum += it;
        return sum;
    }

    bool isPossible(vector<int> &nums, int k, int maxSum){
        int currSum = 0;
        int partitions = 1;
        for(int i=0; i<nums.size(); i++){
            if(currSum + nums[i] <= maxSum){
                currSum += nums[i];
            }
            else{
                currSum = nums[i];
                partitions++;
                if(partitions > k) return false;
            }
        }
        return true;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int low = maxElement(nums);
        long long high = summation(nums);
        int ans;
        while(low <= high){
            long long mid = (low) + (high-low)/2;
            if(isPossible(nums, k, mid)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};