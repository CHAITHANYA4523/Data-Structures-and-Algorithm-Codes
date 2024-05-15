class Solution {
private:    
    void findMinSafeness(queue<pair<int,int>>& q, vector<vector<int>>& minSafenessFactor, vector<vector<int>>& vis, int dist){
        int drow [] = {-1, 0, 1, 0};
        int dcol [] = {0, 1, 0, -1};
        int n = minSafenessFactor.size();
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto it = q.front();
                q.pop();
                int row = it.first;
                int col = it.second;
                minSafenessFactor[row][col] = dist;
                for(int i=0; i<4; i++){
                    int nrow = drow[i] + row;
                    int ncol = dcol[i] + col;
                    if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < n && !vis[nrow][ncol]){
                        vis[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                    }
                }
            }
            dist++;
        }
    }
    bool check(queue<pair<int,int>>& q, vector<vector<int>>& minSafenessFactor, vector<vector<int>>& vis, int safeDist){
        int drow [] = {-1, 0, 1, 0};
        int dcol [] = {0, 1, 0, -1};
        int n = minSafenessFactor.size();
        // Reinitialize vis and q for each check
        vis.assign(n, vector<int>(n, 0));
        while (!q.empty()) q.pop();
        if(minSafenessFactor[0][0] < safeDist) return false;
        q.push({0, 0});
        vis[0][0] = 1;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int row = it.first;
            int col = it.second;
            if(row == n-1 && col == n-1) return true;
            for(int i=0; i<4; i++){
                int nrow = drow[i] + row;
                int ncol = dcol[i] + col;
                if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < n && !vis[nrow][ncol]){
                    if(minSafenessFactor[nrow][ncol] < safeDist) continue;
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
        return false;
    }
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> minSafenessFactor(n, vector<int>(n, 1e9));
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    vis[i][j] = 1;
                    q.push({i, j});
                }   
            }
        }
        findMinSafeness(q, minSafenessFactor, vis, 0);
        int low = 0, high = n, ans = 0;
        while(low <= high){
            int mid = (low) + (high-low)/2;
            if(check(q, minSafenessFactor, vis, mid)){
                ans = mid;
                low = mid+1;
            }
            else high = mid-1;
        }
        return ans;
    }
};
