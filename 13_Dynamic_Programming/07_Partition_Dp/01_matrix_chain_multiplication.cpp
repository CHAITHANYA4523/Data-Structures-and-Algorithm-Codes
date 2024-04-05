#include <bits/stdc++.h> 
int minOperations(int i, int j, vector<int> &arr, vector<vector<int>> &dp){
    if(i == j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int mini =  INT_MAX;

    for(int k=i; k<=j-1; k++){
        int operations = arr[i-1]*arr[k]*arr[j] + minOperations(i, k,arr, dp)
                                 + minOperations(k+1, j,arr, dp);
        mini = min(mini, operations);
    }
    return dp[i][j] = mini;
}
int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<int>> dp(N, vector<int>(N, -1));
    //index i start from 1.
    return minOperations(1, N-1, arr, dp);
}

/*T.C - O(N^3)*/


//Tabulation

#include <bits/stdc++.h> 
int matrixMultiplication(vector<int> &arr, int N){
    vector<vector<int>> dp(N, vector<int>(N, 0));
    //if i == j (base case)
    for(int i=1; i<N; i++) dp[i][i] = 0;
    //in bottom up we start from small pieces and build up to large pieces
    //so j should start from i + 1 and go upto N-1 in the inner for loop
    for(int i=N-1; i>=1; i--){
        for(int j=i+1; j<N; j++){
            int mini =  INT_MAX;
            for(int k=i; k<j; k++){
                int operations = arr[i-1]*arr[k]*arr[j] + dp[i][k]
                                + dp[k+1][j];
                mini = min(operations, mini);
            }
            dp[i][j] = mini;
        }
    }
    //i and j values passed to the function in memoisation technique
    return dp[1][N-1];
}

/*T.C - O(N^3)*/