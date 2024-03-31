//memoisation
class Solution {
private:
    int memoisation(vector<int> &nums, int ind, int prevInd, vector<vector<int>> &dp){
        if(ind == nums.size()) return 0;
        if(dp[ind][prevInd+1] != -1) return dp[ind][prevInd+1];
        int notPick = 0 + memoisation(nums, ind+1, prevInd, dp);
        int pick = -1e9;
        //we can pick if it is first index or current element value is 
        //larger than previously picked value
        if(prevInd == -1 || nums[ind] > nums[prevInd]){
            pick = 1 + memoisation(nums, ind+1, ind, dp);
        }
        return dp[ind][prevInd+1] = max(pick, notPick);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        //coordinate shift of prevIndex to handle -1 index value
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return memoisation(nums, 0, -1, dp);
    }
};

//Tabulation
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        //coordinate shift to handle -1 index case
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int i=n-1; i>=0; i--){
            //prev index cannot be greater than the current index
            for(int j=i-1; j>=-1; j--){
                int notPick = dp[i+1][j+1];
                int pick = -1e9;
                if(j == -1 || nums[i] > nums[j]){
                    pick = 1 + dp[i+1][i+1];
                }
                dp[i][j+1] = max(pick, notPick);
            }
        }
        return dp[0][-1+1];
    }
};

//Space optimisation
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> front(n+1, 0), curr(n+1, 0);
        for(int i=n-1; i>=0; i--){
            for(int j=i-1; j>=-1; j--){
                int notPick = front[j+1];
                int pick = -1e9;
                if(j == -1 || nums[i] > nums[j]){
                    pick = 1 + front[i+1];
                }
                curr[j+1] = max(pick, notPick);
            }
            front = curr;
        }
        return front[-1+1];
    }
};

//Approach 2
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        //each individual element can be LIS of length 1
        vector<int> dp(n, 1);
        int maxi = 1; //minimum LIS is 1
        for(int i=0; i<n; i++){
            for(int prev=0; prev<i; prev++){
                if(nums[prev] < nums[i]){
                    dp[i] = max(dp[i], 1 + dp[prev]);
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};

//printing longest increasing subsequence
vector<int> printingLongestIncreasingSubsequence(vector<int> arr, int n) {
   vector<int> dp(n,1);
    vector<int> hash(n,1);
    
    for(int i=0; i<=n-1; i++){
        hash[i] = i; // initializing with current index
        for(int prev_index = 0; prev_index <=i-1; prev_index ++){
            if(arr[prev_index]<arr[i] && 1 + dp[prev_index] > dp[i]){
                dp[i] = 1 + dp[prev_index];
                hash[i] = prev_index;
            }
        }
    }
    int ans = -1;
    int lastIndex = -1;
    for(int i=0; i<=n-1; i++){
        if(dp[i] > ans){
            ans = dp[i];
            lastIndex = i;
        }
    }
    vector<int> temp;
    temp.push_back(arr[lastIndex]);
    
    while(hash[lastIndex] != lastIndex){ // till not reach the initialization value
        lastIndex = hash[lastIndex];
        temp.push_back(arr[lastIndex]);    
    }
    
    // reverse the array 
    reverse(temp.begin(),temp.end());
    
    // cout<<"The subsequence elements are ";
    
    // for(int i=0; i<temp.size(); i++){
    //     cout<<temp[i]<<" ";
    // }
    // cout<<endl;
    
    return temp;
}

//LIS using binary search 
//generate all possible LIS using binary search and  return the length at the end 

#include <bits/stdc++.h>
using namespace std;

// Function to find the length of the longest increasing subsequence
int longestIncreasingSubsequence(int arr[], int n) {
    // Create a temporary vector to store the increasing subsequence
    vector<int> temp;
    temp.push_back(arr[0]);
    int len = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] > temp.back()) {
            // If arr[i] is greater than the last element of temp, extend the subsequence
            temp.push_back(arr[i]);
            len++;
        } else {
            // If arr[i] is not greater, replace the element in temp with arr[i]
            int ind = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            temp[ind] = arr[i];
        }
    }
    return len;
}


/*
Time Complexity: O(N*logN)
Reason: We iterate over the array of size N and in every iteration, we perform a binary search which takes logN time.

Space Complexity: O(N)
Reason: We are using an extra array of size N to store the temp variable.
*/