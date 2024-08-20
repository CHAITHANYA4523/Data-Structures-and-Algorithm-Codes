#include <bits/stdc++.h>
using namespace std;

void innit_code(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
}

const long long M = 1e9+7;

// dp[i][x].first = is it possible to make xor of x from the first i rows
int main() {
    innit_code();
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    vector<vector<pair<int,int>>> dp(n+1, vector<pair<int,int>>(1024, {0, 0}));
    // base cases
    dp[0][0].first = 1;
    for(int i = 1; i <= 1023; i++) dp[0][i].first = 0;
    
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < m; j++){
            for(int x = 0; x <= 1023; x++){
                if(dp[i - 1][x ^ arr[i - 1][j]].first == 1){
                    dp[i][x].first = 1;
                    dp[i][x].second = j;
                }
            }
        }
    }
    
    for(int k = 1; k <= 1023; k++){
        if(dp[n][k].first == 1){
            vector<int> choices(n, -1);
            int row = n, xorValue = k;
            while(row > 0){
                int choice = dp[row][xorValue].second;
                int newXor = xorValue ^ arr[row - 1][choice];
                xorValue = newXor;
                choices[row - 1] = choice + 1;
                row = row - 1;
            }
            cout << "TAK" << endl;
            for(auto it : choices) cout << it << " ";
            return 0;
        }
    }
    cout << "NIE" << endl;
    return 0;
}

// https://codeforces.com/problemset/problem/1151/B