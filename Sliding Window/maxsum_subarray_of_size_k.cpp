class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &arr , int N){
        int i = 0;
        int j = 0;
        long sum = 0;
        long maxi = INT_MIN;
        while(j < N){
            sum += arr[j];
            if(j-i+1 < K){
                j++;
            }
            else if(j-i+1 == K){
                maxi = max(maxi, sum);
                sum -= arr[i];
                i++;
                j++;
            }
        }
        return maxi;
    }
    
};

/*
Time Complexity (O(N)):
The code uses a sliding window approach with two pointers (i and j) to iterate through the array once. The while loop runs in O(N) time, where N is the size of the input vector arr.

Space Complexity (O(1)):
The space complexity is constant as the code uses a fixed number of variables (i, j, sum, and maxi) regardless of the size of the input array. The space complexity is O(1).
*/