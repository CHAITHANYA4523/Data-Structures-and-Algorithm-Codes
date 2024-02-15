class Solution{
    private:
    vector<int> topoSort(int K, vector<int> adj[]){
        int inDegree[K] = {0};
        vector<int> topo;
        queue<int> q;
        for(int i=0; i<K; i++){
            for(auto it:adj[i]){
                inDegree[it]++;
            }
        }
        for(int i=0; i<K; i++){
            if(inDegree[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:adj[node]){
                inDegree[it]--;
                if(inDegree[it] == 0) q.push(it);
            }
        }
        return topo;
    }
    public:
    string findOrder(string dict[], int N, int K) {
        vector<int> adj[K];
        //traversing upto N-1 to get pairs
        for(int i=0; i<N-1; i++){
            string s1 = dict[i];
            string s2 = dict[i+1];
            int length = min(s1.size(), s2.size());
            for(int ptr=0; ptr<length; ptr++){
                if(s1[ptr] != s2[ptr]){
                    // assing 0 to 1st character, 1 to 2nd and so on to perform toposort
                    adj[s1[ptr]-'a'].push_back(s2[ptr]-'a');
                    break;
                }
            }
        }
        vector<int> topo = topoSort(K, adj);
        string result = "";
        for(int i=0; i<topo.size(); i++){
            result += topo[i]+'a';
        }
        return result;
        
    }
};

/*
Time Complexity: O(N*len)+O(K+E), where N is the number of words in the dictionary, ‘len’ is the length up to the index where the first inequality occurs, K = no. of nodes, and E = no. of edges.

Space Complexity: O(K) + O(K)+O(K)+O(K) ~ O(4K), O(K) for the indegree array, and O(K) for the queue data structure used in BFS(where K = no.of nodes), O(K) for the answer array and O(K) for the adjacency list used in the algorithm.
*/