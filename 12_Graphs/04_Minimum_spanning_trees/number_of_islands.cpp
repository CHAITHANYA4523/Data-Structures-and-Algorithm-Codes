class DisjointSet{
	vector<int> rank, parent, size;
public:
	DisjointSet(int n){
		//work for both zero-based and one-based
		rank.resize(n+1, 0);
		parent.resize(n+1);
		//initialise size array with 1(single nodes initially) 
		size.resize(n+1, 1);
		//go until n for one-based indexing
		for(int i=0; i<=n; i++){
			parent[i] = i;
		}
	}
	int findUltimateParent(int node){
		if(node == parent[node]) return node;
		//for logrithmic time complexity
		//findUltimateParent(parent[node]);
		//for path compression store in parent[node]
		return parent[node] = findUltimateParent(parent[node]);
	}

	void unionByRank(int u, int v){
		int ultimateParentOf_u = findUltimateParent(u);
		int ultimateParentOf_v = findUltimateParent(v);
		if(ultimateParentOf_u == ultimateParentOf_v) return;
		else{
			//smaller rank node gets attached to bigger rank node
			if(rank[ultimateParentOf_u] < rank[ultimateParentOf_v]){
				parent[ultimateParentOf_u] = ultimateParentOf_v;
			}
			else if(rank[ultimateParentOf_u] > rank[ultimateParentOf_v]){
				parent[ultimateParentOf_v] = ultimateParentOf_u;
			}
			//ranks are equal (attach anyone to anyone)
			//here attaching ultimate parent of v to u so,
			//increase rank of u
			else{
				parent[ultimateParentOf_v] = ultimateParentOf_u;
				rank[ultimateParentOf_u]++;
			}
		}
	}
	void unionBySize(int u, int v){
		int ultimateParentOf_u = findUltimateParent(u);
		int ultimateParentOf_v = findUltimateParent(v);
		if(ultimateParentOf_u == ultimateParentOf_v) return;
		else{
			
			if(size[ultimateParentOf_u] < size[ultimateParentOf_v]){
				parent[ultimateParentOf_u] = ultimateParentOf_v;
				size[ultimateParentOf_v] += size[ultimateParentOf_u];
			}
			else{
				parent[ultimateParentOf_v] = ultimateParentOf_u;
				size[ultimateParentOf_u] += size[ultimateParentOf_v];
			}
		}
	}
};

class Solution{
public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        int count = 0;
        vector<int> ans;
        vector<vector<int>> visited(n, vector<int> (m, 0));
        DisjointSet ds(n*m);
        int rowPath[] = {-1, 0, 1, 0};
        int colPath[] = {0, 1, 0, -1};
        for(auto it:operators){
            int row = it[0];
            int col = it[1];
            // to generate 0 1 2 3 .. across rows upto last cell
            int currNode = (row*m) + col;
            // if we come across the same node which is visited previously 
            // add the current count(components) to the ans array.
            if(visited[row][col] == 1){
                ans.push_back(count);
                continue;
            }
            //whenever a new island is formed increase count of islands
            visited[row][col] = 1;
            count++;
            for(int i=0; i<4; i++){
                int nrow = rowPath[i]+row;
                int ncol = colPath[i]+col;
                if(nrow >= 0 && ncol >=0 && nrow < n && ncol < m){
                    int adjNode = (nrow*m) + ncol;
                    if(visited[nrow][ncol] == 1 && 
                    // if both nodes have same parents then they are already connected 
                    // so, don't decrease the island count
                    ds.findUltimateParent(currNode) != ds.findUltimateParent(adjNode)){
                        count--;
                        ds.unionBySize(currNode, adjNode);
                    }
                }
            }
            ans.push_back(count);   
        }
        return ans;
    }
};

/*
Appraoch: Consider adjacent cells with 1's as a single connected component and count the 
number of such components formed.

Time Complexity: O(Q*4α) ~ O(Q) where Q = no. of queries. The term 4α is so small that it can be considered constant.

Space Complexity: O(Q) + O(N*M) + O(N*M), where Q = no. of queries, N = total no. of rows, M = total no. of columns. The last two terms are for the parent and the size array used inside the Disjoint set data structure. The first term is to store the answer.
*/