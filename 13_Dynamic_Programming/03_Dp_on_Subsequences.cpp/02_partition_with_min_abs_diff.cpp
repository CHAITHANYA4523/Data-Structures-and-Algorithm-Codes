//Memoisation
int findWaysUtil(int ind, int target, vector<int>& arr, vector<vector<int>> &dp){

    if(ind == 0){
            if(target==0 && arr[0]==0)
                return 2;
            if(target==0 || target == arr[0])
                return 1;
            return 0;
    }
    
    if(dp[ind][target]!=-1)
        return dp[ind][target];
        
    int notTaken = findWaysUtil(ind-1,target,arr,dp);
    
    int taken = 0;
    if(arr[ind]<=target)
        taken = findWaysUtil(ind-1,target-arr[ind],arr,dp);
        
    return dp[ind][target]= notTaken + taken;
}

int findWays(vector<int> &num, int k){
    int n = num.size();
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    return findWaysUtil(n-1,k,num,dp);
}

//Space optimisation
int minSubsetSumDifference(vector<int>& arr, int n){
	int sum = 0;
	for(int i=0; i<n; i++) sum += arr[i];
	vector<bool> prev(sum+1, false);
	prev[0] = true;
	if(arr[0] <= sum){
		prev[arr[0]] = true;
	}
	for(int ind=1; ind<n; ind++){
		vector<bool> curr(sum+1, false);
		curr[0] = true;
		for(int target=1; target<=sum; target++){
			bool notPick = prev[target];
			bool pick = false;
			if(arr[ind] <= target){
				pick = prev[target-arr[ind]];
			}
			curr[target] = pick || notPick;
		}
		prev = curr;
	}
	int mini = 1e9;
	for(int i=0; i<sum; i++){
		if(prev[i] == true){
			int diff = abs(i - (sum - i));
            mini = min(mini, diff);
		}
	}
	return mini;
}
