//Memoization
class Solution {
private:
    int maxAmount(int n, vector<int>& nums, vector<int> &dp){
        //base case(we arrived at zero because we did not pick index 1)
        if(n == 0){
            return nums[n];
        } 
        if(n < 0) return 0;
        if(dp[n] != -1) return dp[n];
        //we cannot pick adjacent index if we pick current index
        int pick = nums[n] + maxAmount(n-2, nums, dp);
        //current index not picked so, move to adjacent index and add 0(not picked)
        int notPick = 0 + maxAmount(n-1, nums, dp);
        return dp[n] = max(pick, notPick);
    }
public:
    int rob(vector<int>& nums){
        int n = nums.size()-1;
        vector<int> dp(n+1, -1);
        return maxAmount(n, nums, dp);   
    }
};

/*
Time Complexity: The time complexity of this solution is O(n), where n
 is the size of the input array nums. This is because each element in the nums array is processed once.

Space Complexity: The space complexity of this solution is also O(n), due to the auxiliary dp array that is used to store intermediate results. The size of the dp array is equal to the size of the input array nums.
*/


//Space optimisation

class Solution {
public:
    int rob(vector<int>& nums){
        int n = nums.size();
        //prev for pick at index 0 and prev2 for negative index case
        int prev = nums[0], prev2 = 0, currMax = INT_MIN;
        for(int i=1; i<n; i++){
            //take prev2 value as it is if the index accessed is not less than zero(avoiding negative index value)
            int pick = nums[i];
            if(i > 1) pick += prev2;
            int notPick = 0 + prev;
            currMax = max(pick, notPick);
            prev2 = prev;
            prev = currMax;
        }
        return prev;
    }
};

/*
Time Complexity: O(N)
Reason: We are running a simple iterative loop

Space Complexity: O(1)
Reason: We are not using any extra space.
*/


//House Robbery 2 (first and last houses are considered to be adjacent)
class Solution {
public:
    int rob(vector<int>& nums){
        int n = nums.size();
        //prev for pick at index 0 and prev2 for negative index case
        int prev = nums[0], prev2 = 0, currMax = INT_MIN;
        for(int i=1; i<n; i++){
            //take prev2 value as it is if the index accessed is not less than zero(avoiding negative index value)
            int pick = nums[i];
            if(i > 1) pick += prev2;
            int notPick = 0 + prev;
            currMax = max(pick, notPick);
            prev2 = prev;
            prev = currMax;
        }
        return prev;
    }
};

long long int houseRobber(vector<int> &validHouse){
    int n = validHouse.size();
    //one for considering first house and excluding last house and vice versa.
    vector<int> temp1, temp2;
    for(int i=0; i<n; i++){
        if(i != 0) temp1.push_back(validHouse[i]);
        if(i != n-1) temp2.push_back(validHouse[i]);
    }
    return max(rob(temp1), rob(temp2));
}

/*
Time Complexity: O(N)
Reason: We are running a simple iterative loop

Space Complexity: O(1)
Reason: We are not using any extra space.
*/