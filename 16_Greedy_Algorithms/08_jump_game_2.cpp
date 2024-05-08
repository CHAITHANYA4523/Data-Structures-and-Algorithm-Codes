class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int targetIndex = nums.size()-1;
        int idx = targetIndex - 1;
        int count = 0;
        while(targetIndex > 0){
            int minPossibleIndex = -1;
            for(int i = targetIndex-1; i>=0; i--){
                if(i + nums[i] >= targetIndex) minPossibleIndex = i;
            }
            count++;
            targetIndex = minPossibleIndex;
        }
        return count;
    }
};

//O(N^2) , O(N)

class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int farthest = 0;
        int current = 0;
        for(int i=0; i<nums.size()-1; i++){
            farthest = max(farthest, nums[i] + i);
            if(i == current){
                current = farthest;
                jumps++;
            }
        }
        return jumps;
    }
};


//O(N), o(1)

