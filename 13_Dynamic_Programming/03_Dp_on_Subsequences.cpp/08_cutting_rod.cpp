//memoisation
int memoisation(vector<int> &price, int ind, int n, vector<vector<int>> &dp){
	if(ind == 0){
		//curr rod length * prices since index value is 1 (curr_rodlength/ind = curr_rodlength). 
		return price[0]*(n);
	}
	int notTake = memoisation(price, ind-1, n, dp);
	int take = INT_MIN;
	int rodLength = ind+1;
	if(n >= rodLength){
		take = price[ind] + memoisation(price, ind, n-rodLength, dp);
	}
	return max(notTake, take);
}

int cutRod(vector<int> &price, int n)
{
	vector<vector<int>> dp(n, vector<int>(n+1, -1));
	return memoisation(price, n-1, n, dp);
}


//tabulation
