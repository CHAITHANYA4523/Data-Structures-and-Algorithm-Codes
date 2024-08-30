#include <bits/stdc++.h>
using namespace std;

void innit_code(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
}

const long long M = 1e9+7;

int main() {
    innit_code();
    long long n;
    cin >> n;
    vector<vector<long long>> arr(n, vector<long long>(n));
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }
    vector<long long> dp((1 << n), 0);
    // one way to match no one (zero pairs)
    dp[0] = 1;
    
    for(int bitmask = 0; bitmask < (1 << n) - 1; bitmask++){
        int i = __builtin_popcount(bitmask); // Number of men already paired
        for(int j = 0; j < n; j++){
            if(arr[i][j]){
                if(bitmask & (1 << j)) continue; // Check if j-th woman is already paired
                int newMask = bitmask | (1 << j); // Set j-th woman as paired
                dp[newMask] += dp[bitmask];
                dp[newMask] %= M;
            }
        }
    }
    
    cout << dp[(1 << n) - 1] % M << endl;
    
    return 0;
}
