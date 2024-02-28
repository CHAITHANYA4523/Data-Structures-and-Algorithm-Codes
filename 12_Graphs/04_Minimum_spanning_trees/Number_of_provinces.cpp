class DisjointSet{
private:
    vector<int> parent, rank;
public:
    DisjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1, 0);
        for(int i=0; i<=n; i++){
            parent[i] = i;
        }
    }
    int ultimateParent(int node){
        if(node == parent[node]) return node;
        return parent[node] = ultimateParent(parent[node]);
    }
    void unionByRank(int u, int v){
        int ulp_u = ultimateParent(u);
        int ulp_v = ultimateParent(v);
        if(ulp_u == ulp_v) return; 
        else{
            if(rank[ulp_u] == rank[ulp_v]){
                parent[ulp_u] = ulp_v;
            }
            else if(rank[ulp_u] < rank[ulp_v]){
                parent[ulp_u] = ulp_u;
            }
            else{
                parent[ulp_u] = ulp_v;
                rank[ulp_v]++;
            }
        }
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int m = isConnected[0].size();
        DisjointSet ds(n);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(isConnected[i][j] == 1) ds.unionByRank(i+1, j+1);
            }
        }
        int count = 0;
        for(int i=1; i<=n; i++){
            if(ds.ultimateParent(i) == i) count++;
        }
        return count;
    }
};


/*
Space Complexity: The space complexity is primarily determined by the size of the DisjointSet data structure, which is proportional to the number of nodes, n. Therefore, the space complexity is O(n).

Time Complexity: The time complexity is determined by the operations performed on the DisjointSet data structure.

The ultimateParent function performs a path compression operation, which has an amortized time complexity of nearly O(1).
The unionByRank function also has a time complexity of nearly O(1) due to the union by rank operation.
The findCircleNum function has a time complexity of O(n^2) because it contains two nested loops that iterate over the isConnected matrix.
Therefore, the overall time complexity of the code is dominated by the findCircleNum function, making the time complexity O(n^2).
*/