/*
Important Note: 
If the start value is greater than end value, the answer is still possible because after the mod operation the value will shrink and can reach the end, similarly if at any point, the value is greater than end we cannot discard it as it may lead to the answer at a future point after the mod operation.
Use this test case where arr = {6, 8}, start = 4608, end = 4288, after 12 operations start will reach the end.
So, we need a distance array to keep the steps in check(within the limit).
*/

class Solution{
    public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        if(start == end) return 0;
        int MOD = 1e5;
        queue<pair<int,int>> q;
        vector<int> distance(MOD, 1e9);
        distance[start] = 0;
        //{steps, node}
        q.push({0, start});
        while(!q.empty()){
            int steps = q.front().first;
            int node = q.front().second;
            q.pop();
            for(auto &x:arr){
                int adjNode = (node*x)%MOD;
                // If the no. of multiplications are less than before
                // in order to reach a number, we update the distance array.
                if(steps+1 < distance[adjNode]){
                    distance[adjNode] = steps+1;
                    if(end == adjNode) return steps+1;
                    q.push({steps+1, adjNode});
                }
            }
        }
        return -1;
    }
};

/*
Time Complexity : O(100000 * N) 
Where ‘100000’ are the total possible numbers generated by multiplication (hypothetical) and N = size of the array with numbers of which each node could be multiplied.

Space Complexity :  O(100000 * N) 
Where ‘100000’ are the total possible numbers generated by multiplication (hypothetical) and N = size of the array with numbers of which each node could be multiplied. 100000 * N is the max possible queue size. The space complexity of the dist array is constant.
*/