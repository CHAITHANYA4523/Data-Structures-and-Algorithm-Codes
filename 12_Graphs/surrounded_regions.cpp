class Solution {
private:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &board, int n, int m){
        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, 1, 0, -1}; 
        vis[row][col] = 1;
        for(int i=0; i<4; i++){
            int nrow = delrow[i]+row;
            int ncol = delcol[i]+col;
            if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m){ 
                if(board[nrow][ncol] == 'O' && !vis[nrow][ncol]){
                    dfs(nrow, ncol, vis, board, n, m); 
                }
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0)); 
        // traverse first row and last row 
        for(int j = 0 ; j<m;j++) {
            // check for unvisited Os in the boundary rows
            // first row 
            if(!vis[0][j] && board[0][j] == 'O') {
                dfs(0, j, vis, board, n, m); 
            }
            // last row 
            if(!vis[n-1][j] && board[n-1][j] == 'O') {
                dfs(n-1,j,vis,board, n, m); 
            }
        }
        for(int i = 0;i<n;i++) {
            // check for unvisited Os in the boundary columns
            // first column 
            if(!vis[i][0] && board[i][0] == 'O') {
                dfs(i, 0, vis, board, n, m); 
            }
            // last column
            if(!vis[i][m-1] && board[i][m-1] == 'O') {
                dfs(i, m-1, vis, board, n, m); 
            }
        }
        // if unvisited O then convert to X
        for(int i = 0;i<n;i++) {
            for(int j= 0 ;j<m;j++) {
                if(!vis[i][j] && board[i][j] == 'O') 
                    board[i][j] = 'X'; 
            }
        } 
    }
};

/*
Time Complexity: O(N) + O(M) + O(NxMx4) ~ O(N x M), For the worst case, every element will be marked as ‘O’ in the matrix, and the DFS function will be called for (N x M) nodes and for every node, we are traversing for 4 neighbors, so it will take O(N x M x 4) time. Also, we are running loops for boundary elements so it will take O(N) + O(M).

Space Complexity ~ O(N x M), O(N x M) for the visited array, and auxiliary stack space takes up N x M locations at max. 
*/