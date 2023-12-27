//Bfs Approach
class Solution{
private:
    void bfs(int N, int row, int col, int targetRow, int targetCol, vector<vector<int>> &distance){
        queue<pair<int, int>> q;
        q.push({row, col});
        distance[row][col] = 0;
        int rowPath[] = {-1,-2,1,2,-1,-2,1,2};
        int colPath[] = {2,1,2,1,-2,-1,-2,-1};
        while (!q.empty()) {
            pair<int, int> currentPos = q.front();
            q.pop();
            for(int i=0; i<8; i++){
                int nrow = currentPos.first + rowPath[i];
                int ncol = currentPos.second + colPath[i];
                if(nrow>=0 && nrow<N && ncol>=0 && ncol<N && distance[nrow][ncol] == -1){
                    distance[nrow][ncol] = distance[currentPos.first][currentPos.second] + 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N){
	    int currRow = KnightPos[0] - 1;
	    int currCol = KnightPos[1] - 1;
	    int targetRow = TargetPos[0] - 1;
	    int targetCol = TargetPos[1] - 1;
	    vector<vector<int>> distance(N, vector<int>(N, -1));
	    bfs(N, currRow, currCol, targetRow, targetCol, distance);
	    if(distance[targetRow][targetCol] == -1) return -1;
	    return distance[targetRow][targetCol];
	}
};

/*
BFS (Breadth-First Search):
Time Complexity: O(N^2)
Space Complexity: O(N^2)

BFS visits each vertex once and inspects all edges of each vertex once. Therefore, the time complexity is proportional to the number of vertices and edges, which in this case is N^2. The space complexity is determined by the maximum size of the queue, which can be up to N^2 in the worst case scenario when all vertices are in the queue.
*/

//Dfs Approach
// this approach is giving tle for some inputs
class Solution{
    private:
    void dfs(int N, int row, int col, int targetRow, int targetCol, int count, int &ans, vector<vector<int>> &vis){
        if(row == targetRow && col == targetCol){
            ans = min(count, ans);
            return;
        }
        int rowPath[] = {-1,-2,1,2,-1,-2,1,2};
        int colPath[] = {2,1,2,1,-2,-1,-2,-1};
        for(int i=0; i<8; i++){
            int nrow = row + rowPath[i];
            int ncol = col + colPath[i];
            if(nrow>=0 && nrow<N && ncol>=0 && ncol<N){
                if(!vis[nrow][ncol] || vis[nrow][ncol] > count+1){
                    vis[nrow][ncol] = count+1;
                    dfs(N, nrow, ncol, targetRow, targetCol, count+1, ans, vis);
                }
            }
        }
    }
public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N){
	    int currRow = *KnightPos.begin() - 1;
	    int currCol = *(KnightPos.begin()+1) - 1;
	    int targetRow = *TargetPos.begin() - 1;
	    int targetCol = *(TargetPos.begin()+1) - 1;
	    int count = 0, ans = INT_MAX;
	    vector<vector<int>> vis(N, vector<int>(N, 0));
	    dfs(N, currRow, currCol, targetRow, targetCol, count, ans, vis);
	    if(ans == INT_MAX) return -1;
	    return ans;
	}
};

/*
DFS (Depth-First Search):
Time Complexity: O(N^2)
Space Complexity: O(N^2)

DFS also visits each vertex once and inspects all edges of each vertex once, leading to a time complexity of O(N^2).The space complexity is determined by the maximum depth of the recursion tree, which can be up to N^2 in the worst case scenario when all vertices are in the recursion stack.

Please note that these complexities are specific to this problem where the graph is represented as a 2D grid of size N×N. In general, the time and space complexities of BFS and DFS would depend on the number of vertices (V) and edges (E) in the graph, and would be O(V+E) for both time and space complexities. But in this case, since the graph is a grid, the number of vertices and edges are both proportional to N^2, leading to the complexities mentioned above.
*/