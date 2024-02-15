class Solution{
    public:
        vector<int> minimumTime(int n,vector<vector<int>> &edges,int m)
        {
            vector<int> inDegree(n+1, 0);
            vector<int> ans(n, 0);
            vector<int> adj[n+1];
            queue<int> q;
            for(auto it:edges){
                adj[it[0]].push_back(it[1]);
                inDegree[it[1]]++;
            }
            for(int i=1; i<n+1; i++){
                if(inDegree[i] == 0){
                    //store ans 
                    ans[i-1] = 1;
                   q.push(i); 
                }
            }
            while(!q.empty()){
                int node = q.front();
                q.pop();
                for(auto it:adj[node]){
                    inDegree[it]--;
                    // store timer 1 more than the node pointing it in zero based indexing ans
                    ans[it-1] = ans[node-1] + 1;
                    if(inDegree[it] == 0) q.push(it);
                }
            }
            return ans;
        }
};