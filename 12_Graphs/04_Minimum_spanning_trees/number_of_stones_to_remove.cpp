class DisjointSet{
private:
    vector<int> parent, size;
public:
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
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxRow = 0;
        int maxCol = 0;
        for (auto it : stones) {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }
        DisjointSet ds(maxRow + maxCol + 1);
        //{node, present in components marked}
        unordered_map<int, int> stoneNodes;
        for (auto it : stones) {
            int nodeRow = it[0];
            // column is started from next number of row count
            int nodeCol = it[1] + maxRow + 1;
            ds.unionBySize(nodeRow, nodeCol);
            //mark present in a component
            stoneNodes[nodeRow] = 1;
            stoneNodes[nodeCol] = 1;
        }

        int count = 0;
        // gives no of components
        for (auto it:stoneNodes) {
            if (ds.ultimateParent(it.first) == it.first) {
                count++;
            }
        }
        int n = stones.size(); // total stones
        // calculated by removing component size - 1 and adding all components 
        // result in n - no of components.(no of nodes of all components = total stones)
        return n - count;
    }
};

/*
Time Complexity: O(N), where N = total no. of stones. Here we have just traversed the given stones array several times. And inside those loops, every operation is apparently taking constant time. So, the time complexity is only the time of traversal of the array.

Space Complexity: O(2* (max row index + max column index)) for the parent and size array inside the Disjoint Set data structure.
*/