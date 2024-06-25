//523 problem on leetcode
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int prefixSum = 0, n = nums.size();
        unordered_map<int,int> firstOccur;
        firstOccur[0] = 0;
        for(int i=0; i<nums.size(); i++){
            prefixSum = (prefixSum + nums[i])%k;
            if(firstOccur.find(prefixSum) != firstOccur.end()){
                if(i+1 - firstOccur[prefixSum] >= 2) return true;
            }
            else{
                firstOccur[prefixSum] = i+1;
            }
        }
        return false;
    }
};