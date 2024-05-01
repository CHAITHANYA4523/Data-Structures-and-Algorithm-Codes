class Solution{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        long long ans = 0;
        priority_queue <long long, vector<long long>, greater<long long>> pq(arr, arr+n);
        if(n == 1) return 0;
        //if pq.size() is 1 then we don't have two ropes to add
        while(pq.size() > 1){
            long long top1 = pq.top();
            pq.pop();
            long long top2 = pq.top();
            pq.pop();
            ans += top1 + top2;
            pq.push(top1+top2);
        }
        return ans;
    }
};