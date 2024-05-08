class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1) return true;
        int targetIndex = nums.size()-1;
        int idx = targetIndex - 1;
        while(idx >= 0){
            if(idx + nums[idx] >= targetIndex){
                targetIndex = idx;
            }
            idx--;
        }
        if(targetIndex == 0) return true;
        return false;
    }
};

//check whether the targetIndex is reachable from previous index values in backwards direction
