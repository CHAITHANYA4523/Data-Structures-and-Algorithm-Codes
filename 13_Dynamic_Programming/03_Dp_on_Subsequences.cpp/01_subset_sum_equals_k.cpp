//Memoisation
class Solution{
private:
    bool checkSubsetSum(vector<int> &arr, int ind, int target, vector<vector<bool>> &dp){
    // If the target sum is 0, we have found a subset
    if(target == 0){
        return true;
    }
    // If we have reached the first element in 'arr'
    if(n == 0) return target == arr[ind];
    //for a particular index if the corresponding target occured in
    //previous computations resulted in zero this will also result 
    //in zero so we can return (overlapping case)
    if(dp[ind][target] != false) return true;
    bool notPick = checkSubsetSum(arr, ind-1, target, dp);
    bool pick = false;
    if(arr[ind] <= target){
        pick = checkSubsetSum(arr, ind-1, target-arr[ind], dp);
    }
    return dp[n][target] = pick || notPick;
}
public:
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size()-1;
        //dp[index][target]
        vector<vector<bool>> dp(n+1, vector<bool>(target+1, false));
        return checkSubsetSum(arr, n, target, dp);
    }
};

/*
Time Complexity: O(N*K)
Reason: There are N*K states therefore at max ‘N*K’ new problems will be solved.

Space Complexity: O(N*K) + O(N)
Reason: We are using a recursion stack space(O(N)) and a 2D array ( O(N*K)).
*/

//Tabulation
class Solution{
public:
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        //dp[index][target]
        vector<vector<bool>> dp(n, vector<bool>(sum+1, false));
        // Base case: If the target sum is 0, we can always achieve it by taking no elements
        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }
        // Base case: If the first element of 'arr' is less than or equal to 'k', set dp[0][arr[0]] to true
        if (arr[0] <= k) {
            dp[0][arr[0]] = true;
        }
        //start from index 1 as 0 index is already computed.
        for(int index=1; index<n; index++){
            //check for target ranging from 1 to sum as 0 is already covered in base case
            for(int target=1; target<=sum; target++){
                bool notPick = dp[index-1][target];
                bool pick = false;
                if(arr[index] <= target){
                    pick = dp[index-1][target-arr[index]];
                }
                dp[index][target] = pick || notPick;
            }
        }
        return dp[n-1][sum];
    }
};

/*
Time Complexity: O(N*K)
Reason: There are two nested loops

Space Complexity: O(N*K)
Reason: We are using an external array of size ‘N*K’. Stack Space is eliminated.
*/

//Tabulation
class Solution{
public:
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
         // Initialize a vector 'prev' to store the previous row of the DP table
        vector<bool> prev(k + 1, false);
        // Base case: If the target sum is 0, we can always achieve it by taking no elements
        prev[0] = true;
        // Base case: If the first element of 'arr' is less than or equal to 'k', set prev[arr[0]] to true
        if (arr[0] <= k) {
            prev[arr[0]] = true;
        }
        //start from index 1 as 0 index is already computed.
        for(int index=1; index<n; index++){
            // Initialize a new row 'cur' to store the current state of the DP table
            vector<bool> cur(k + 1, false);
            // Base case: If the target sum is 0, we can achieve it by taking no elements
            cur[0] = true;
            //check for target ranging from 1 to sum as 0 is already covered in base case
            for(int target=1; target<=sum; target++){
                bool notPick = dp[index-1][target];
                bool pick = false;
                if(arr[index] <= target){
                    pick = dp[index-1][target-arr[index]];
                }
                dp[index][target] = pick || notPick;
            }
        }
        return prev[sum];
    }
};

/*
Time Complexity: O(N*K)
Reason: There are three nested loops

Space Complexity: O(K)
Reason: We are using an external array of size ‘K+1’ to store only one row.
*/