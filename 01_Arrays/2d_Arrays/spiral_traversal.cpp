class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top = 0, left = 0;
        int right = matrix[0].size()-1, bottom = matrix.size()-1;
        vector<int> ans;
        while(top <= bottom && left <= right){
            //left to right (top is constant)
            for(int i=left; i<=right; i++){
                ans.push_back(matrix[top][i]);
            }
            //to avoid duplicate printing
            top++;
            //top to bottom (right is constant)
            for(int i=top; i<=bottom; i++){
                ans.push_back(matrix[i][right]);
            }
            //to avoid duplicate printing
            right--;
            //avoid incase both crosses each other(incase of single row(n*1))
            if(top <= bottom){
                //right to left (bottom is constant)
                for(int i=right; i>=left; i--){
                    ans.push_back(matrix[bottom][i]);
                }
                //to avoid duplicate printing
                bottom--;
            }
            //avoid incase both crosses each other(incase of single column(1*m))
            if(left <= right){
                //bottom to top (left is constant)
                for(int i=bottom; i>=top; i--){
                    ans.push_back(matrix[i][left]);
                }
                //to avoid duplication
                left++;
            }
        }
        return ans;
    }
};

/* 

time complexity: of this code is O(n), where n is the total number of elements in the matrix. This is because each element in the matrix is visited and added to the `ans` vector exactly once.

space complexity: of this code is also O(n), where n is the total number of elements in the matrix. This is due to the space required for the `ans` vector to store the elements of the matrix.

In both cases, n = {number of rows}*{number of columns} of the matrix. The time and space complexities are linear because they scale directly with the size of the input matrix.
*/