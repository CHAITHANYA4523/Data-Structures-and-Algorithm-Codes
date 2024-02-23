class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        for(auto it:edges){
            dist[it[0]][it[1]] = it[2];
            dist[it[1]][it[0]] = it[2];
        }
        for(int i=0; i<n; i++) dist[i][i] = 0;
        for(int via=0; via<n; via++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(dist[i][via] + dist[via][j] < dist[i][j]){
                        dist[i][j] = dist[i][via] + dist[via][j];
                    }
                }
            }
        }
        int minCityCount = n, resCity;
        for(int i=0; i<n; i++){
            int cityCount = 0;
            for(int j=0; j<n; j++){
                if(dist[i][j] <= distanceThreshold) cityCount++;
            }
            if(cityCount <= minCityCount){
                resCity = i;
                minCityCount = cityCount;
            }
        }
        return resCity;
    }
};

/*
Time Complexity: O(V3), as we have three nested loops each running for V times, where V = no. of vertices.

Space Complexity: O(V2), where V = no. of vertices. This space complexity is due to storing the adjacency matrix of the given graph.
*/