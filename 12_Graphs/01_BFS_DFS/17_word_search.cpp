class Solution {
private:
    bool checkWordExists(vector<vector<char>>& board, string word, 
                         vector<vector<int>>& vis, int row, int col, int k) {
        if (k == word.size()) return true; // found
        int n = board.size(), m = board[0].size();
        vis[row][col] = 1;
        int rowPath[] = {-1, 0, 1, 0};
        int colPath[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; ++i) {
            int nrow = rowPath[i] + row;
            int ncol = colPath[i] + col;
            if (nrow >= 0 && ncol >= 0 && ncol < m && nrow < n && !vis[nrow][ncol]) {
                if (board[nrow][ncol] == word[k]) {
                    if (checkWordExists(board, word, vis, nrow, ncol, k + 1)) return true;
                }
            }
        }
        vis[row][col] = 0;
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (word[0] == board[i][j]) {
                    if (checkWordExists(board, word, vis, i, j, 1)) return true;
                } 
            }
        }
        return false;
    }
};
