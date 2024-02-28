//Disjoint set using union by rank/union by size
//use respective functions
#include <bits/stdc++.h>
using namespace std;

void innit_code(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif // ONLINE_JUDGE
}

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

int main() {
	innit_code();
	DisjointSet ds(7);
	ds.unionBySize(1,2);
	ds.unionBySize(2,3);
	ds.unionBySize(4,5);
	ds.unionBySize(6,7);
	ds.unionBySize(5,6);

	//check if 3 and 7 have same ultimate parent
	if(ds.findUltimateParent(3) == ds.findUltimateParent(7)){
		cout << "Same\n" << endl;
	}
	else cout << "Not Same\n" << endl;

	ds.unionBySize(3,7);

	//check if 3 and 7 have same ultimate parent
	if(ds.findUltimateParent(3) == ds.findUltimateParent(7)){
		cout << "Same\n" << endl;
	}
	else cout << "Not Same\n" << endl;

    return 0;
}

/*
Note: We need to connect smaller rank nodes to larger rank nodes as fewer (smaller rank nodes < higher rank nodes) need to take more traversal time.

Space Complexity: The space complexity of this DSU implementation is O(n), where n
is the number of elements. This is because we maintain two arrays (or vectors in this case), parent and rank, each of size n.

Time Complexity: The time complexity for the operations findUltimateParent and unionByRank is nearly constant, O(1), due to the path compression and union by rank optimizations. However, in the worst-case scenario (when the tree becomes a skewed tree), it can go up to O(logn)
*/
