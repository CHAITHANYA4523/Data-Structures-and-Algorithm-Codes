//Approach
/*
Say you have four stones a,b,c,d.
first you smash b against c, you get (b-c)
now you smash (b-c) against a
you get a-(b-c) which is same as (a+c)-(b)
now you smash d against (a+c)-b
you get d-((a+c)-b) which is same as (d+b)-(a+c).
Basically for the given stones we can create two sets,the sum of second set of stones to be subtracted from sum of first one.
ideally we want sum of each set to be sum(stones)/2 so that they cancel each other out.

So to solve the problem we try to select a set of stones such that their sum comes as close as possible to sum(stones)/2 from the lower side.
Clearly this subproblem is analogous to the knapsack problem.

Since we went from the lower side we have created the second set, that is the set to be subtracted. The first set then becomes sum-dp[n][sum/2].
Therefore the answer becomes sum-2*(dp[n][sum/2])
*/
class Solution {
private:
    int summation(vector<int> &stones){
        int sum = 0;
        for(auto it:stones){
            sum += it;
        }
        return sum;
    }
    int solve(vector<int> &stones, int idx, int sum, int target, vector<vector<int>> &dp){
        if(idx < 0) return 0;
        if(dp[idx][sum] != -1) return dp[idx][sum];
        int notPick = solve(stones, idx-1, sum, target, dp);
        int pick = 0;
        if(sum + stones[idx] <= target){
            pick = stones[idx] + solve(stones, idx-1, sum + stones[idx], target, dp);
        }
        return dp[idx][sum] = max(pick, notPick);
    }
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = summation(stones);
        int n = stones.size();
        vector<vector<int>> dp(n, vector<int>((sum/2 + 1, -1));
        int secondSet = solve(stones, n-1, 0, sum/2,  dp);
        int firstSet = sum - secondSet;
        return abs(firstSet - secondSet);
    }
};


class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int total = 0;
        for (int stone:stones) {
            total += stone;
        }
        vector<int> dp(total/2 + 1, 0);
        for (int stone:stones) {
            for (int i=total/2; i>=stone; --i) {
                dp[i] = max(dp[i], dp[i-stone] + stone);
            }
        }
        return total-2*dp[total/2];
    }
};
