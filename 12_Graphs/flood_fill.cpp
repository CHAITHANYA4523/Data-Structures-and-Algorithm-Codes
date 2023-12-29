//bfs traversal

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc] == newColor) return image;
        int initialColor = image[sr][sc];
        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = newColor;
        //up, right, down, left
        int adjrow[] = {-1, 0, 1, 0};
        int adjcol[] = {0, 1, 0, -1};
        while(!q.empty()){
            pair<int, int> curr = q.front();
            q.pop();
            for(int i=0; i<4; i++){
                int nrow = curr.first + adjrow[i];
                int ncol = curr.second + adjcol[i];
                if(nrow >=0 && nrow < image.size() && ncol < image[0].size() && ncol >=0){
                    if(image[nrow][ncol] == initialColor){
                        q.push({nrow, ncol});
                        image[nrow][ncol] = newColor;
                    }
                }
            }
        }
        return image;
    }
};

/*
Time: O(M * N), where M <= 50 is number of rows, N <= 50 is number of columns in the matrix.
Space: O(M * N), the space used by the queue in bfs, in worst case is O(M * N)
*/

//dfs traversal
class Solution {
public:
    
    void dfs(vector<vector<int>>& image, int i, int j,int val, int newColor)
    {
        if(i<0 || i>=image.size() || j<0 || j>= image[0].size() || image[i][j] == newColor || image[i][j] != val)
        {
            return;
        }
        image[i][j] = newColor;
        dfs(image,i-1,j,val,newColor);
        dfs(image,i+1,j,val,newColor);
        dfs(image,i,j-1,val,newColor);
        dfs(image,i,j+1,val,newColor);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)
    {
        int val = image[sr][sc];
        dfs(image,sr,sc,val,newColor);
        return image;
    }
};

/*
Time Complexity: O(NxM + NxMx4) ~ O(N x M)
For the worst case, all of the pixels will have the same colour, so DFS function will be called for (N x M) nodes and for every node we are traversing for 4 neighbours, so it will take O(N x M x 4) time.

Space Complexity: O(N x M)
O(N x M) for recursive stack space as it takes up N x M locations at max. 
*/