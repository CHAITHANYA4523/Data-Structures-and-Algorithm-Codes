//using DisjointSet and unionBySize

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
                size[ulp_v] += size[ulp_u];
            }
        }
    }
};


class Solution{
    public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]){
        //{weight, {node, adjNode}}
       vector<pair<int,pair<int,int>>> edges;
        for(int i=0; i<V; i++){
           for(auto it:adj[i]){
               int adjNode = it[0];
               int wt = it[1];
               int node = i;
               edges.push_back({wt, {node, adjNode}});
            }
        }
       //sort based on weights (automatically sorts based on wt(it.first in pairs))
       sort(edges.begin(), edges.end());
       int mstWt = 0;
       DisjointSet ds(V);
       for(auto it:edges){
           int wt = it.first;
           int u = it.second.first;
           int v = it.second.second;
           //if both nodes don't have same parent take them under 
           // minimum spanning tree and update the size by taking union
           if(ds.ultimateParent(u) != ds.ultimateParent(v)){
               mstWt += wt;
               ds.unionBySize(u, v);
           }
       }
       return mstWt;
    }
};