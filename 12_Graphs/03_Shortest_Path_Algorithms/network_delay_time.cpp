
// Note: The code is not working for some test cases in leetcode
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int MOD = (int)(1e9 + 7);
        vector<pair<int,long long>> adj[n]; // Change second type to long long
        // from -> {to, time}
        for(auto it:roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        vector<int> timer(n, INT_MAX);
        timer[0] = 0;
        vector<long long> ways(n, 0); 
        ways[0] = 1;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        //{time, node}
        pq.push({0, 0});
        long long ans = 0;
        while(!pq.empty()){
            long long time = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                int adjNode = it.first;
                long long edgeW = it.second;
                //this is the first time coming with shortest distance so 
                if(time + edgeW < timer[adjNode]){
                    timer[adjNode] = time + edgeW;
                    ways[adjNode] = ways[node];
                    pq.push({time + edgeW, adjNode});
                }
                else if(time + edgeW == timer[adjNode]){
                    //add all the paths that are passing through the 
                    // node and reaching towards adjNode
                    ways[adjNode] = (ways[adjNode] + ways[node]) % MOD;
                }
            }
        }
        return ways[n-1] % MOD;
    }
};

