class Solution {
private:  
    bool isSafe(vector<string> &board, int row, int col, int n){
        int dupRow = row;
        int dupCol = col;
        while(col >= 0 && row >= 0){
            if(board[row][col] == 'Q') return false;
            col--;
            row--;
        }
        row = dupRow;
        col = dupCol;

        while(col >= 0){
            if(board[row][col] == 'Q') return false;
            col--;
        }

        row = dupRow;
        col = dupCol;
        while(col >= 0 && row < n){
            if(board[row][col] == 'Q') return false;
            col--;
            row++;
        }
        return true;
    }
    void solve(vector<string> &board, vector<vector<string>> &ans, int n, int col){
        if(col == n){
            ans.push_back(board);
            return;
        }

        for(int row = 0; row < n; row++){
            if(isSafe(board, row, col, n)){
                board[row][col] = 'Q';
                solve(board, ans, n, col + 1);
                board[row][col] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for(int i = 0; i < n; i++){
            board[i] = s;
        }

        int col = 0;
        solve(board, ans, n, col);

        return ans;

    }
};