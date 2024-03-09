class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        for(auto & x:nums) nums[abs(x)-1] = -abs(nums[abs(x)-1]);
        for(int i=0; i<nums.size(); i++){
            if(nums[i] > 0) ans.push_back(i+1);
        }
        return ans;
    }
};
/*
Mark as seen by Negation - Space Optimized

There's another way that we can compute ans without using any extra space (except the output ans). We know that nums is of size is n and it contains only elements from [1, n]. We can map each element of the range [1, n] to the indices of nums from [0, n-1].

Thus, the above property can be used to mark if an element from range [1, n] is present in nums or not.

How?
We can iterate over nums and for each element, we know it can be mapped to index nums[i]-1. We can therefore mark the element nums[i] as present in nums by making the element at index nums[i]-1 negative. Thus after iterating the array, we have -

nums[i] < 0 or nums[i] is negative only if the element i+1 is present in the array.
nums[i] > 0 or nums[i] is positive only if the element i+1 is not present in the array
For eg. Consider the following example -

nums = [4,3,2,7,8,2,3,1]
1. '4' is present in nums. Mark as present by negating nums[4-1] = nums[3].  Thus, nums[3] = -7
   => nums = [4,3,2,-7,8,2,3,1]
	
2. '3' is present in nums. Mark as present by negating nums[3-1] = nums[2].  Thus, nums[2] = -2
   => nums = [4,3,-2,-7,8,2,3,1]

3. '2' is present in nums. Thus, nums[1] = -3
   => nums = [4,-3,-2,-7,8,2,3,1]
   
4. '7' is present in nums. Thus, nums[6] = -3
   => nums = [4,-3,-2,-7,8,2,-3,1]

5. '8' is present in nums. Thus, nums[7] = -1
   => nums = [4,-3,-2,-7,8,2,-3,-1]
   
6. '2' is present in nums. Thus, nums[1] = -3
   => nums = [4,-3,-2,-7,8,2,-3,-1]   
  
7. '3' is present in nums. Thus, nums[2] = -2
   => nums = [4,-3,-2,-7,8,2,-3,-1]   

7. '1' is present in nums. Thus, nums[0] = -4
   => nums = [-4,-3,-2,-7,8,2,-3,-1]   

Now, the only elements nums[i] which are positive are those where 'i+1' is not found in nums
These are => nums[4] and nums[5].
That means 5 and 6 an not present in the initial nums array
*/