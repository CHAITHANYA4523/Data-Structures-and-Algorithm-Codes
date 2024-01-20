
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        // 1. mark numbers (num < 0) and (num > n) with a special marker number (n+1) 
        // (we can ignore those because if all number are > n then we'll simply return 1)
        for(int i=0; i<n; i++){
            if(nums[i] <= 0 || nums[i] > n){
                nums[i] = n+1;
            }
        }
        // note: all number in the array are now positive, and on the range 1..n+1
        // 2. mark each cell appearing in the array, by converting the index for that number to negative
        for(int i=0; i<n; i++){
            int number = abs(nums[i]);
            if(number > n) continue;
            number--; // for zero based indexing
            // prevents double negative operations
            if(nums[number] > 0) nums[number] = -1 * nums[number];
        }
        // 3. find the first cell which isn't negative (doesn't appear in the array)
        for(int i=0; i<n; i++){
            if(nums[i] >= 0) return i+1;
        }
        // 4. no positive numbers were found, which means the array contains all numbers 1..n
        return n+1;
    }
};

/*
First loop: This loop goes through each element in the array. If an element is less than or equal to 0, or greater than the size of the array n, it sets that element to n+1. This is done because we’re only interested in positive integers up to n, and any negative number or number greater than n can be safely ignored for the purpose of finding the first missing positive integer.

Second loop: This loop is essentially marking the presence of positive integers in the array by flipping the sign of the corresponding index. Here’s how it works:
It iterates over each element in the nums array.
For each element, it takes the absolute value and assigns it to number. This is because the previous loop might have changed some values in the array to negative.
If number is greater than the size of the array n, it skips the current iteration and moves to the next one. This is because we’re only interested in positive integers up to n.
If the value at the index number-1 in the array is positive, it changes that value to negative. This is a way of marking that the positive integer number exists in the array. The reason for using number-1 as the index is that array indices start at 0, while the positive integers start at 1.

Third loop: This loop goes through the array again and returns the index of the first positive number. Since we’ve used the indices of the array to mark the presence of numbers, a positive number at an index indicates that the number corresponding to that index is missing from the array. If all indices are negative, it means all integers from 1 to n are present, so the function returns n+1, which is the next smallest positive integer.
*/