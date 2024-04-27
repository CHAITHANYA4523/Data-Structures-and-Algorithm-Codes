class Solution {
public:
    // Function to generate all possible subsets of a given set of numbers
    vector<vector<int>> subsets(vector<int>& nums) {
        // Initialize the result vector to store all subsets
        vector<vector<int>> result;
        // Get the number of elements in the input vector
        int n = nums.size();
        // Calculate the total number of subsets possible for a set of size 'n'
        // We can represent all subsets of a set with n elements using a binary number of n bits
        // Each bit position corresponds to whether the corresponding element is included or not
        // For example, for a set with 3 elements, there are 2^3 = 8 possible subsets
        // which can be represented using binary numbers from 000 to 111
        // So, we use bitwise left shift operation to calculate 2^n efficiently
        int subsetCount = (1 << n);
        // Iterate over all possible subsets
        for(int mask = 0; mask < subsetCount; mask++){
            // Initialize a vector to represent the current subset being generated
            vector<int> subset;
            // Iterate through the bits of the mask
            for(int i = 0; i < n; i++){
                // Check whether the ith bit is set or not in the mask
                // If the bit is set, include the corresponding element in the subset
                if((mask & (1 << i)) != 0){
                    subset.push_back(nums[i]);
                }
            }
            // Add the current subset to the result vector
            result.push_back(subset);
        }
        // Return the vector containing all subsets
        return result;
    }
};


/*
Time Complexity: (O(2^n*n))
- The outer loop iterates over (2^n) subsets.
- The inner loop iterates over each bit in the mask, which takes (O(n)) time.

Space Complexity: (O(2^n*n))
- The result vector stores all (2^n) subsets, each containing up to (n) elements.
- Additionally, the space required for the mask and the subset vectors is negligible compared to the total space required.
*/

//for handling duplicates 
class Solution{
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        // Sort the input array to handle duplicates
        sort(nums.begin(), nums.end());
        // 2 power n
        int subsetCount = (1 << n);
        for (int mask = 0; mask < subsetCount; mask++) {
            vector<int> subset;
            // Loop through bits of the mask
            for (int i = 0; i < n; i++) {
                // Check whether ith bit is set or not in mask
                // If set, add the number to the subset vector
                if ((mask & (1 << i)) != 0) {
                    subset.push_back(nums[i]);
                }
            }
            // Skip duplicate subsets
            if (find(result.begin(), result.end(), subset) == result.end()) {
                result.push_back(subset);
            }
        }
        return result;
    }
};