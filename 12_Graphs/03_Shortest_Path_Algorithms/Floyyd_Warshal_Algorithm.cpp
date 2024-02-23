class Solution{
    public:
	void shortest_distance(vector<vector<int>>&matrix){
	    int n = matrix.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                //unreachable nodes are at infinity
                if(matrix[i][j] == -1){
                    matrix[i][j] = (int)1e9;
                }
                //distance to node itself is zero
                if(i == j) matrix[i][j] = 0;
            }
        }
        //going from source to target via every node
	    for(int via=0; via<n; via++){
	        for(int i=0; i<n; i++){
	            for(int j=0; j<n; j++){
	                if(matrix[i][via] + matrix[via][j] < matrix[i][j]){
	                    matrix[i][j] = matrix[i][via] + matrix[via][j];
	                }
	            }
	        }
	    }
	    //changing the unreached nodes to -1 which is given in
	    //the question which we changed to 1e9 for solving
	    for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 1e9){
                    matrix[i][j] = -1;
                }
            }
        }
	    
	}
};

/*
Time Complexity: O(V3), as we have three nested loops each running for V times, where V = no. of vertices.

Space Complexity:O(1) no additoinal space is used
*/