class Solution {
private:
    vector<int> dp; // Dynamic programming array to store the minimum number of balanced substrings till index i
    vector<vector<int>> preSum; // Prefix sum array to store the frequency of each character till index i

    // Recursive function to find the minimum number of balanced substrings
    int solve(int i, string s){
        int n = s.size();
        if(i == -1) return 0; // Base case: If i is -1, return 0
        if(dp[i] != -1) return dp[i]; // If the value is already computed, return it

        int minAns = n; // Initialize the minimum answer with the size of the string
        for(int j=i; j>=0; j--){
            bool isPossible = true;
            int maxFreq = 0;
            for(int k=0; k<26; k++){
                // Calculate the current frequency of the kth character
                int currFreq = preSum[i][k] - (j-1 >= 0 ? preSum[j-1][k] : 0);
                // If the maximum frequency is not equal to the current frequency, then it is not possible to form a balanced string
                if(maxFreq != 0 && currFreq != 0 && maxFreq != currFreq) isPossible = false;
                // Update the maximum frequency
                maxFreq = max(maxFreq, currFreq);
            }
            // If it is not possible to form a balanced string, continue to the next iteration
            if(!isPossible) continue;
            // Update the minimum answer with the minimum of the current minimum answer and 1 + solve(j-1, s)
            // This is done only when all characters in the substring have the same frequency (i.e., the substring is balanced)
            // The '1+' represents the current balanced substring, and 'solve(j-1, s)' represents the minimum number of balanced substrings in the remaining string
            minAns = min(minAns, 1 + solve(j-1, s));
        }
        // Store the minimum answer in the dp array and return it
        return dp[i] = minAns;
    }

public:
    // Function to find the minimum number of substrings that you can partition s into
    int minimumSubstringsInPartition(string s) {
        int n = s.size();
        dp = vector<int>(n+1, -1); // Initialize the dp array with -1
        preSum = vector<vector<int>>(n+1, vector<int>(26, 0)); // Initialize the preSum array with 0

        // Update the frequency of the first character in the string
        preSum[0][s[0]-'a'] = 1;
        for(int i=1; i<n; i++){
            // Update the frequency of the ith character in the string
            preSum[i][s[i]-'a']++;
            for(int j=0; j<26; j++){
                // Update the frequency of the jth character till index i
                preSum[i][j] += preSum[i-1][j]; 
            }
        }
        // Call the solve function with n-1 as the argument and return its result
        return solve(n-1, s);
    }
};

