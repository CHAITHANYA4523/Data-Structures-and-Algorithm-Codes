#include <bits/stdc++.h>
// int memoization(vector<int> &weight, vector<int> &value, int ind, int maxWeight, vector<vector<int>> &dp){
// 	if(ind == 0){
// 		int noOfTimesCanPick = maxWeight/weight[0];
// 		return noOfTimesCanPick*value[0];
// 	}
// 	if (dp[ind][maxWeight] != -1) {
//         return dp[ind][maxWeight];
//     }
// 	int notPick = memoization(weight, value, ind-1, maxWeight, dp);
// 	int pick = INT_MIN;
// 	if(weight[ind] <= maxWeight){
// 		pick = value[ind] + memoization(weight, value, ind, maxWeight-weight[ind], dp);
// 	}
// 	return max(pick, notPick);
// }

int unboundedKnapsack(int n, int maxWeight, vector<int> &profit, vector<int> &weight) {
    vector<int>prev(maxWeight+1,0);
    //base case 
    for(int i=0;i<=maxWeight;i++){
        prev[i]=(i/weight[0])*profit[0];
    }
    for(int ind=1;ind<n;ind++){
        vector<int>curr(maxWeight+1,0);
        for(int W=0;W<=maxWeight;W++){
            int notTake=prev[W];
            int take=INT_MIN;
            if(weight[ind]<=W)
            take=profit[ind]+curr[W-weight[ind]];
            curr[W]=max(notTake,take); 
        }
        prev=curr;
    }
    return prev[maxWeight];
}