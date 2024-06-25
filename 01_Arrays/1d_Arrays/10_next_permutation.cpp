class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index = -1;
        for(int i=nums.size()-2; i>=0; i--){
            if(nums[i]<nums[i+1]){
                index = i;
                break;
            }
        }
        if(index == -1){
            reverse(nums.begin(),nums.end());
            return;
        }
        //the array is in increasing order from the end
        for(int i=nums.size()-1; i>index; i--){
            if(nums[i] > nums[index]){
                swap(nums[i],nums[index]);
                break;
            }
        }
        sort(nums.begin() + index + 1, nums.end());
        
    }
};


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index = -1;
        for(int i=nums.size()-2; i>=0; i--){
            if(nums[i]<nums[i+1]){
                index = i;
                break;
            }
        }
        if(index == -1){
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int i=nums.size()-1; i>index; i--){
            if(nums[i] > nums[index]){
                swap(nums[i],nums[index]);
                break;
            }
        }
        //as the array still remains in increasing order from the end even after swapping 
        //we can just reverse the array instead of sorting
        reverse(nums.begin() + index + 1, nums.end());
        
    }
};