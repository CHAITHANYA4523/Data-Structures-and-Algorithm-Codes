//Approach: first create component islands with 1's
//then check for each cell that has vlaue 0 in all four directions 
//and add the sizes of adjacent components with with 1 (current cell).

class DisjointSet{   
public:
    vector<int> parent, size;
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(int i=0; i<=n; i++){
            parent[i] = i;
        }
    }
    int ultimateParent(int node){
        if(node == parent[node]) return node;
        return parent[node] = ultimateParent(parent[node]);
    }
    void unionBySize(int u, int v){
        int ulp_u = ultimateParent(u);
        int ulp_v = ultimateParent(v);
        if(ulp_u == ulp_v) return;
        else{
            if(size[ulp_u] < size[ulp_v]){
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
            else{
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
    }
    int findSize(int node){
        return size[node];
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n+1);
        int rowPath[] = {-1, 0, 1, 0};
        int colPath[] = {0, 1, 0, -1};
        int oneCount = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    oneCount++;
                    int row = i;
                    int col = j;
                    int currNode = (row*n) + col;
                    // Union adjacent 1's to form connected components.
                    for(int i=0; i<4; i++){
                        int nrow = rowPath[i] + row;
                        int ncol = colPath[i] + col;
                        if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < n){
                            if(grid[nrow][ncol] == 1){
                                int adjNode = nrow*n + ncol;
                                ds.unionBySize(currNode, adjNode);
                            }
                        }
                    }
                }
            }
        }

        // If the grid consists of only 1's, return the total number of cells.
        if(oneCount == n*n) return n*n;
        // If the grid consists of only 0's, return 1 (assuming we can make a single cell island).
        if(oneCount == 0) return 1;
        
        int ans = INT_MIN; 
        unordered_set<int> s; // Set to store unique parent nodes of adjacent components.
        
        unordered_set<int> s;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int count = 0; // Initialize count for the current cell.
                int row = i;
                int col = j;
                if(grid[i][j] == 0){ // If the cell value is 0.
                    count++; // Increment count for the current cell.
                    // Check adjacent cells for 1's and add their component sizes.
                    for(int i=0; i<4; i++){
                        int nrow = rowPath[i] + row;
                        int ncol = colPath[i] + col;
                        if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < n){
                            if(grid[nrow][ncol] == 1){
                                int adjNode = nrow*n + ncol;
                                s.insert(ds.ultimateParent(adjNode));
                            }
                        }
                    }
                    // Calculate the total size of the island by adding sizes of adjacent components.
                    for(auto it:s){
                        count = count+ds.findSize(it);
                    }
                    s.clear(); // Clear the set for the next iteration.
                    ans = max(ans, count); // Update the maximum island size.
                }
            }
        }
        return ans;
    }
};

/*
Time Complexity: O(N^2)+O(N^2) ~ O(N^2) where N = total number of rows of the grid. Inside those nested loops, all the operations are taking apparently constant time. So, O(N^2) for the nested loop only, is the time complexity.

Space Complexity: O(2*N^2) where N = the total number of rows of the grid. This is for the two arrays i.e. parent array and size array of size N^2 inside the Disjoint set.
*/