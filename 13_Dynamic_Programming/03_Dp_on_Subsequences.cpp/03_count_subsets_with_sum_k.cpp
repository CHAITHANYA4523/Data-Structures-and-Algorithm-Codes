int findWays(vector<int>& arr, int k){
    int M = 1e9 + 7;
    int n = arr.size();
	vector<int> prev(k+1, 0);
    if(arr[0] == 0) 
        prev[0] = 2;
    else
        prev[0] = 1;
    if(arr[0] != 0 && arr[0] <= k)
        prev[arr[0]]=1;
    for(int ind = 1; ind<n; ind++){
        vector<int> curr(k+1, 0);
        curr[0] = 1;
        for(int target = 1; target<= k; target++){
            int notPick = prev[target];
            int pick = 0;
            if(arr[ind] <= target){
                pick = prev[target-arr[ind]];
            }
            curr[target] = (pick + notPick)%M;
        }
        prev = curr;
    }
    return prev[k];
}
