/*
A Bitonic Sequence is a sequence of numbers that is first strictly increasing and then strictly decreasing.

A strictly ascending order sequence is also considered bitonic, with the decreasing part as empty, and same for a strictly descending order sequence.

For example, the sequences [1, 3, 5, 3, 2], [1, 2, 3, 4] are bitonic, whereas the sequences [5, 4, 1, 4, 5] and [1, 2, 2, 3] are not.
You are given an array 'arr' consisting of 'n' positive integers.

Find the length of the longest bitonic subsequence of 'arr'.
Example :
Input: 'arr' = [1, 2, 1, 2, 1]
Output: 3

Explanation: The longest bitonic subsequence for this array will be [1, 2, 1]. Please note that [1, 2, 2, 1] is not a valid bitonic subsequence, because the consecutive 2's are neither strictly increasing, nor strictly decreasing.
*/

int longestBitonicSubsequence(vector<int>& arr, int n){
	vector<int> dp1(n, 1);
	vector<int> dp2(n, 1);
	vector<int> bitonic(n);
    //here
	for(int i=0; i<n; i++){
		for(int  j=0; j<i; j++){
			if(arr[j] < arr[i] && dp1[j] + 1 > dp1[i]){
				dp1[i] = 1 + dp1[j];
                //here dp1[i] is the LIS upto this index
			}
		}
	}
    //find longest increasing subsequence from last 
	for(int i=n-1; i>=0; i--){
		for(int  j=n-1; j>i; j--){
			if(arr[j] < arr[i] && dp2[j] + 1 > dp2[i]){
				dp2[i] = 1 + dp2[j];
			}
		}
	}
	int ans = 0;
	for(int i=0; i<n; i++){
        //we are taking 1 less because of repetition of element in both sequences
		ans = max(ans, (dp1[i]+dp2[i]) - 1);
	}
	return ans;
}
