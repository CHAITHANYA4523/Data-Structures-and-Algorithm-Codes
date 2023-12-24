#include <bits/stdc++.h>
void subsequence(vector<char> &ans, char input[], int index, int size){
    //base case
    if(index == size){
        for(auto x:ans) cout << x; // print characters
        if(ans.size() == 0) cout << "";
        cout << endl;
        return;
    }
    //element added to subsequence
    ans.push_back(input[index]);
    subsequence(ans, input, index+1, size);//pick case 
    //element not added to subsequence
    ans.pop_back();
    subsequence(ans, input, index+1, size);//not pick case
}
void printSubsequences(char input[]) {
    vector<char> ans;
    int n = strlen(input);
    subsequence(ans, input, 0,n);
}


//subsequence sum equals k (time limited exceeded)

bool subsequence(int index, vector<int>& arr, int k, int sum) {
    // Base case
    if (index == arr.size()) {
        if (sum == k)
            return true;
        else
            return false;
    }
    if (sum > k)
        return false;
    // Because we need only one subsequence to prove presence, therefore no need to perform further recursion calls
    // Just return true from there.
    // Take case
    if (subsequence(index + 1, arr, k, sum + arr[index]))
        return true;
    // Not take case
    if (subsequence(index + 1, arr, k, sum - arr[index]))
        return true;
    // If none of the take and not take recursion calls generate a subsequence, return false.
    return false;
}

bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
    return subsequence(0, arr, k, 0);
}

//count subsequences whose sum == k

int subsequence(int index, vector<int>& arr, int k, int sum) {
    // Base case
    if (index == arr.size()) {
        if (sum == k)
            return 1;
        else
            return 0;
    }
    //take case
    int left = subsequence(index + 1, arr, k, sum + arr[index]);
        
    // Not take case
    int right = subsequence(index + 1, arr, k, sum - arr[index]);
    return left + right;
}

int checkSubsequenceSum(int n, vector<int>& arr, int k) {
    return subsequence(0, arr, k, 0);
}