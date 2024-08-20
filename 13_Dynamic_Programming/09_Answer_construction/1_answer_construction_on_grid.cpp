#include <bits/stdc++.h>
using namespace std;

void innit_code(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
}

const long long M = 1e9+7;
int n = 3, m = 3;
vector<vector<pair<int,int>>> dp(n, vector<pair<int,int>>(m, {-1, 0}));
//0 -> down direction
//1 -> right direction

int solve(vector<vector<int>> &grid, int i, int j){
    if(i == n || j == m) return 1e9;
    if(i == n - 1 && j == m - 1) return grid[n - 1][m - 1];
    if(dp[i][j].first != -1) return dp[i][j].first;
    int ans1 = solve(grid, i + 1, j);
    int ans2 = solve(grid, i, j + 1);
    if(ans1 < ans2){
        dp[i][j].second = 0;
    }
    else{
        dp[i][j].second = 1;
    }
    return dp[i][j].first = grid[i][j] + min(ans1, ans2);
}
int main() {
    innit_code();
    vector<vector<int>> grid(n, vector<int>(m));
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin >> grid[i][j];
        }
    }
    cout << solve(grid, 0, 0) << endl;
    pair<int,int> current = {0, 0};
    cout << current.first << " " << current.second << endl;
    while(current != make_pair(n-1, m-1)){
        cout << current.first << " " << current.second << endl;
        if(dp[current.first][current.second].second == 0)
            current.first++;
        else 
            current.second++;
    }
    cout << current.first << " " << current.second << endl;
    return 0;
}
