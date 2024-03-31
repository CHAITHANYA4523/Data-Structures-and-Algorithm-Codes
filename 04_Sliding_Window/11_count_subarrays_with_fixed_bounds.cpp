//TLE 
// Not optimised 
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        long long n = nums.size();
        for(int i=0; i<n; i++){
            bool minKFound = false;
            bool maxKFound = false;
            for(int j=i; j<n; j++){
                if(nums[j] == minK) minKFound = true;
                if(nums[j] == maxK) maxKFound = true;
                if(nums[j] > maxK || nums[j] < minK){
                    break;
                }
                if(minKFound == true && maxKFound == true){
                    cout << nums[j] << " ";
                    ans++;
                }
            }
        }
        return ans;
    }
};

//sliding window approach
/*
Intuition
We can use a sliding window approach to find all subarrays with minimum value minK and maximum value maxK. We can keep track of the start index of the current subarray and update it whenever we encounter a value that is less than minK or greater than maxK.
When we find a subarray with both minK and maxK, we can count the number of subarrays that can be formed by taking the minimum index of minK and maxK as the starting point and the current index as the ending point.

Approach
Initialize res to 0, start to 0, and minFound and maxFound to false.
Iterate over the array nums.
If the current value num is less than minK or greater than maxK, set minFound and maxFound to false and update start to i+1.
If num is equal to minK, set minFound to true and update minStart to i.
If num is equal to maxK, set maxFound to true and update maxStart to i.
If minFound and maxFound are both true, add (min(minStart, maxStart) - start + 1) to res.
Return res.
*/

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        long long n = nums.size();
        bool minFound = false, maxFound = false;
        long long start = 0, minStart = 0, maxStart = 0;
        long long j = 0;
        while(j<n){
            int num = nums[j];
            if (num < minK || num > maxK){
                minFound = false;
                maxFound = false;
                start = j+1;
            }
            if (num == minK){
                minFound = true;
                minStart = j;
            }
            if (num == maxK){
                maxFound = true;
                maxStart = j;
            }
            if(minFound && maxFound){
                ans += (min(minStart, maxStart) - start + 1);
            }
            j++;
        }
        return ans;
    }
};