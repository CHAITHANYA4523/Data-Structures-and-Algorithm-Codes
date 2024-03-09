class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int row = 0, col = 0, n = mat.size(), m = mat[0].size();
        vector<int> ans;
        bool up = true;
        while(row<n && col<m){
            if(up == true){
                //moving upwards
                while(row > 0 && col < m-1){
                    ans.push_back(mat[row][col]);
                    row--;
                    col++;
                }
                ans.push_back(mat[row][col]);
                //change direction
                if(col == m-1){
                    row++;
                }
                //move right for another downward direction traversal if col
                // is not equal to m-1
                else{
                    col++;
                }
            }
            else{
                //moving down
                while(col > 0 && row < n-1){
                    ans.push_back(mat[row][col]);
                    row++;
                    col--;
                }
                ans.push_back(mat[row][col]);
                //change direction 
                if(row == n-1){
                    col++;
                }
                //move down for another upward direction traversal if row
                // is not equal to n-1
                else{
                    row++;
                }
            }
            //toogle the direction
            up = !up;
        }
        return ans;
    }
};

/*
The time complexity of the code is O(n*m), where n is the number of rows and m is the number of columns in the matrix. This is because each element in the matrix is visited once.

The space complexity of the code is O(n*m), where n is the number of rows and m is the number of columns in the matrix. This is because a new vector ans is created to store all the elements of the matrix.
*/