
//concept
/*
left = 0, right = 2
right
index -   0 1 3 4 5
element - 1 2 1 2 3
left
Map
1 -> 2
2 -> 1
But now think what to do?
if (left++)
then -> we might miss the subarrays
that contain index O
Example - [1,2,1,2]
if (right++)
then -> we might miss inner
subarrays
Example [2,1]
ans = 2
unique element = 2

to overcome this 

sum of subarrays with at most k distinct integers = sum of subarrays with exactly k distinct integers + sum of subarrays with atmost k-1 distinct integers
from which we can conclude 
sum of subarrays with exactly k distinct integers = sum of subarrays with atmost k distinct integers + sum of subarrays with atmost k-1 distinct integers
*/
class Solution {
private:
    int subarrrayWithAtmostKDistinct(vector<int>& nums, int k){
        int i=0, j = 0;
        int ans = 0;
        unordered_map<int,int> mp;
        while(j<nums.size()){
            mp[nums[j]]++;
            if(mp.size() > k){
                while(mp.size() > k){
                    mp[nums[i]]--;
                    if(mp[nums[i]] == 0) mp.erase(nums[i]);
                    i++;
                }
            }
            ans = ans + j-i+1;
            j++;
        }
        return ans;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int finalAns = subarrrayWithAtmostKDistinct(nums, k) - subarrrayWithAtmostKDistinct(nums, k-1);
        return finalAns;
    }
};
