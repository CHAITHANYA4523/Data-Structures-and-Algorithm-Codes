//memoisation
#include <bits/stdc++.h> 

int memoization(vector<int> &weight, vector<int> &value, int ind, int maxWeight, vector<vector<int>> &dp){
	if(maxWeight == 0) return 0;
	if(ind == 0){
		if(weight[ind] <= maxWeight){
			return value[0];
		}
		else return 0;
	}
	if (dp[ind][maxWeight] != -1) {
        return dp[ind][maxWeight];
    }
	int notPick = memoization(weight, value, ind-1, maxWeight, dp);
	int pick = INT_MIN;
	if(weight[ind] <= maxWeight){
		pick = value[ind] + memoization(weight, value, ind-1, maxWeight-weight[ind], dp);
	}
	return max(pick, notPick);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
	vector<vector<int>> dp(n, vector<int>(maxWeight+1, -1));
	return memoization(weight, value, n-1, maxWeight, dp);
}

/*
Time Complexity: O(N*W)
Reason: There are N*W states therefore at max ‘N*W’ new problems will be solved.

Space Complexity: O(N*W) + O(N)
Reason: We are using a recursion stack space(O(N)) and a 2D array ( O(N*W)).
*/

//tabulation
#include <bits/stdc++.h> 

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
	vector<vector<int>> dp(n, vector<int>(maxWeight+1, 0));
    // Base condition: Fill in the first row for the weight of the first item
	for(int w=weight[0]; w<=maxWeight; w++) dp[0][w] = value[0];
	for(int ind=1; ind<n; ind++){
		for(int w=0; w<=maxWeight; w++){
			int notPick = dp[ind-1][w];
			int pick = INT_MIN;
            // Check if the current item can be included without exceeding the knapsack's capacity
			if(weight[ind] <= w){
				pick = value[ind] + dp[ind-1][w-weight[ind]];
			}
			dp[ind][w] = max(pick, notPick);
		}
	}
	return dp[n-1][maxWeight];	
}

/*
Time Complexity: O(N*W)
Reason: There are two nested loops

Space Complexity: O(N*W)
Reason: We are using an external array of size ‘N*W’. Stack Space is eliminated.
*/

//Space optimisation
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
	vector<int> prev(maxWeight+1, 0);
	for(int w=weight[0]; w<=maxWeight; w++) prev[w] = value[0];
	for(int ind=1; ind<n; ind++){
		vector<int> curr(maxWeight+1, 0);
		for(int w=0; w<=maxWeight; w++){
			int notPick = prev[w];
			int pick = INT_MIN;
			if(weight[ind] <= w){
				pick = value[ind] + prev[w-weight[ind]];
			}
			curr[w] = max(pick, notPick);
		}
		prev = curr;
	}
	return prev[maxWeight];	
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
	vector<int> prev(maxWeight+1, 0);
	for(int w=weight[0]; w<=maxWeight; w++) prev[w] = value[0];
	for(int ind=1; ind<n; ind++){
		for(int w=maxWeight; w>=0; w--){
			int notPick = prev[w];
			int pick = INT_MIN;
			if(weight[ind] <= w){
				pick = value[ind] + prev[w-weight[ind]];
			}
			prev[w] = max(pick, notPick);
		}
	}
	return prev[maxWeight];	
}

/*
Time Complexity: O(N*W)
Reason: There are two nested loops.

Space Complexity: O(W)
Reason: We are using an external array of size ‘W+1’ to store only one row.
*/