class Solution{
private:
    void dfs(vector<vector<int>> &m, vector<string> &res, string validPath, vector<vector<int>> &vis, int row, int col){
        vis[row][col] = 1;
        // Arrays to explore the 4 directions: up, right, down, left
        int rowpath[] = {-1, 0, 1, 0};
        int colpath[] = {0, 1, 0, -1};
        int n = m.size();
        // If the current cell is the destination, add the path to the result
        if(row == n-1 && col == n-1){
            res.push_back(validPath);
            return;
        }
        // Explore the 4 directions
        for(int i=0; i<4; i++){
            int nrow = row + rowpath[i];
            int ncol = col + colpath[i];
            // If the new cell is within the grid
            if(nrow >= 0 && nrow < n && ncol >=0 && ncol < n){
                // If the new cell is not visited and not blocked
                if(!vis[nrow][ncol] && m[nrow][ncol] == 1){
                    // Determine the direction
                    string direction;
                    if(i == 0) direction = "U";
                    else if(i == 1) direction = "R";
                    else if(i == 2) direction = "D";
                    else direction = "L";
                    dfs(m, res, validPath + direction, vis, nrow, ncol);
                }
            }
        }
        // Backtrack: unmark the current cell
        vis[row][col] = 0;
    }
public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> res;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        string validPath = "";
        // If the source cell is not blocked, start DFS from the source
        if(m[0][0] == 1) dfs(m, res, validPath, vis, 0, 0);
        if(res.empty()) return {"-1"};
        // Sort the paths in lexicographical order
        sort(res.begin(), res.end());
        return res;
    }
};

/*
Time Complexity: The time complexity of this approach is O((3^N^2)) 3 powered N squared. This is because, in the worst case, you have to explore all possible paths in the maze. For each cell, you have 3 choices (excluding the cell from where you came). So, for a maze of size N x N, the time complexity becomes O((3^N^2)).

Space Complexity: The space complexity of this approach is O(L * X), where L is the length of a path and X is the number of paths. This is because, for each valid path, you are storing the path (which has a length of L) in the result. If there are X such paths, the space required will be O(L * X).
*/