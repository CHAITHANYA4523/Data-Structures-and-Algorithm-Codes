class Solution {
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<vector<int>> dp(n + 1, vector<int>((1 << n), 1e9));
        //base case
        dp[0][0] = 0;
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            for(int bitmask = 0; bitmask < (1 << n); bitmask++){
                for(int j = 0; j < n; j++){
                    if(bitmask & (1 << j)){
                        continue;
                    }
                    else{
                        dp[i][bitmask | (1 << j)] = min(dp[i][bitmask | (1 << j)], 
                        (nums1[i-1] ^ nums2[j]) + dp[i-1][bitmask]);
                        cnt++;
                    }
                }
            }
            
        }
        cout << cnt << endl;
        //every bitmask will be set by end as we consider every element
        return dp[n][(1 << n) - 1];
    }
};


//time complexity - n^2 * (2 ^ n)
//space complexity - n * (2 ^ n)

const int INF = 2e9;
class Solution {
public:
    int minimumXORSum(vector<int>& a, vector<int>& b) {
        int n = a.size();
        vector<int> dp(1<<n, INF);

        dp[0] = 0;  
        for(int mask = 0; mask < (1<<n); mask++) {
            // We check for the i'th element of nums1
            int i = __builtin_popcount(mask);
            for(int j = 0;j<n;j++) {
                // if j is already present in the mask
                if((mask & (1<<j))) continue;

                dp[mask | (1<<j)] = min(dp[mask | (1<<j)], dp[mask] + (a[i] ^ b[j]));
            }
        }
        return dp[(1<<n) - 1];
    }
};

//time complexity - n * (2 ^ n)
//space complexity - (2 ^ n)