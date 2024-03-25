class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mp;
        //initially the sum is zero
        mp[0] = -1;
        int ans = 0;
        int currentBalance = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 1){
                currentBalance++;
            }
            else if(nums[i] == 0){
                currentBalance--;
            }
            //if the current balance occured previously take the current index - prev index
            if(mp.count(currentBalance)){
                int ind = mp[currentBalance];
                int len = i - ind;
                if(len > ans){
                    ans = len;
                }
            }
            //if current balance not found store in the map
            else{
                mp[currentBalance] = i;
            }
        }
        return ans;
    }
};