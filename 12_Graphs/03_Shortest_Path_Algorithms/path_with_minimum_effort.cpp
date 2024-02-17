class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rowPath[] = {-1, 0, 1, 0};
        int colPath[] = {0, 1, 0, -1};
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> distance(n, vector<int>(m, 1e9));
        distance[0][0] = 0;
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        //{absouluteDifference, {row, col}}
        pq.push({0,{0,0}});
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;

            if (row == n - 1 && col == m - 1) return diff;

            for(int i=0; i<4; i++){
                int nrow = row + rowPath[i];
                int ncol = col + colPath[i];
                if(nrow < n && nrow >= 0 && ncol < m && ncol >= 0){
                    //the algo with proceed in whichever direction the diff is least(priority queue application)
                    int newEffort = max(diff, abs(heights[nrow][ncol] - heights[row][col]));
                    if(newEffort < distance[nrow][ncol]){
                        distance[nrow][ncol] = newEffort;
                        pq.push({newEffort, {nrow, ncol}});
                    }
                }
            }
        }
        return 0; // if unreachable
    }
};

// No need of visited matrix as only the minimum effort path values are pushed into the priority queue 

/*
Time Complexity: O( 4*N*M * log( N*M) ) { N*M are the total cells, for each of which we also check 4 adjacent nodes for the minimum effort and additional log(N*M) for insertion-deletion operations in a priority queue } 

Space Complexity: O( N*M ) { Distance matrix containing N*M cells + priority queue in the worst case containing all the nodes ( N*M) }.

Where, N = No. of rows of the binary maze and M = No. of columns of the binary maze.
*/