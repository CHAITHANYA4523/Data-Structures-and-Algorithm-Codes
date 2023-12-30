class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<pair<int,int>, int>> q;
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));
        vector<vector<int>> ans(n, vector<int> (m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 0){
                    q.push({{i,j}, 1});
                }
            }
        }
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int count = q.front().second;
            q.pop();
            vis[row][col] = 1;
            int drow[] = {-1, 0, 1, 0};
            int dcol[] = {0, 1, 0, -1};
            for(int i=0; i<4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m){ 
                    if(mat[nrow][ncol] != 0 && !vis[nrow][ncol]){
                        vis[nrow][ncol] = 1;
                        ans[nrow][ncol] = count;
                        q.push({{nrow,ncol}, count+1});
                    }
                }
            }
        }
        return ans;
    }
};


/*
Time Complexity: O(NxM + NxMx4) ~ O(N x M)

For the worst case, the BFS function will be called for (N x M) nodes, and for every node, we are traversing for 4 neighbors, so it will take O(N x M x 4) time.

Space Complexity: O(N x M) + O(N x M) + O(N x M) ~ O(N x M)

O(N x M) for the visited array, answer matrix, and queue space takes up N x M locations at max. 
*/