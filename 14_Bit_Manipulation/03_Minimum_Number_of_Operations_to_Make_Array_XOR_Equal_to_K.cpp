class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int xorNum = 0;
        for(int i=0; i<nums.size(); i++){
            xorNum = xorNum ^ nums[i];
        }
        xorNum = xorNum ^ k;
        int count = 0;
        while(xorNum){
            if(xorNum & 1) count++;
            xorNum = xorNum>>1;
        }
        return count;
    }
};

//Approach
/*
Calculate the bitwise XOR of all elements of the original array and compare it to k in their binary representation.

For each different bit between the bitwise XOR of elements of the original array and k we have to flip exactly one bit of an element in nums to make that bit equal.
*/