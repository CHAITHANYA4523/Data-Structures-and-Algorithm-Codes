//intuition: no of addtional cables should be 1 less or equal or more than the computer networks. Even a single computer can be considered as a network.

class DisjointSet{
private: 
    vector<int> parent, networkSize;
    int count = 0;
public:
    DisjointSet(int n){
        parent.resize(n+1);
        networkSize.resize(n+1, 1);
        for(int i=0; i<=n; i++){
            parent[i] = i;
        }
    }
    int ultimateParent(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = ultimateParent(parent[node]);
    }
    void unionByNetworkSize(int u, int v){
        int ulp_u = ultimateParent(u);
        int ulp_v = ultimateParent(v);
        //if both computers have same ultimate parent then
        //the cables between them can be used to connect other computers.
        if(ulp_u == ulp_v){
            count++;
            return;
        }
        else{
            if(networkSize[ulp_u] < networkSize[ulp_v]){
                parent[ulp_u] = ulp_v;
                networkSize[ulp_v] += networkSize[ulp_u];
            }
            else{
                parent[ulp_v] = ulp_u;
                networkSize[ulp_u] += networkSize[ulp_v];
            }
        }
    }
    int additionalCables(){
        return count;
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int size = connections.size();
        DisjointSet ds(n);
        for(int i=0; i<size; i++){
            ds.unionByNetworkSize(connections[i][0], connections[i][1]);
        }
        int count = 0;
        for(int i=0; i<n; i++){
            if(ds.ultimateParent(i) == i) count++;
        }
        //if cables are 1 less than networks or more than computers networks(components)
        if(ds.additionalCables()+1 >= count){
            //it takes 1 less cable to connect n networks
            int minNoOfCableConnections =  count-1;
            return minNoOfCableConnections;
        }
        return -1;
    }
};