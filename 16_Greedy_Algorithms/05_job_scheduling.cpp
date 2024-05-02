class Solution{
    public:
    static bool cmp(Job a, Job b){
            return a.profit > b.profit;
        }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n){ 
        // your code here
        int maxi = INT_MIN;
        for(int i=0; i<n; i++){
            maxi = max(arr[i].dead, maxi);
        }
        vector<int> scheduler(maxi+1, -1);
        sort(arr, arr+n, cmp);
        int totalProfit = 0;
        int jobScheduleCount = 0;
        for(int i=0; i<n; i++){
            int currDeadLine = arr[i].dead;
            int currId = arr[i].id;
            int currProfit = arr[i].profit;
            //try to find free slot starting from the deadline of job to maximize profit
            for(int k=currDeadLine; k>0; k--){
                if(scheduler[k] == -1){
                    scheduler[k] = currId;
                    totalProfit += currProfit; 
                    jobScheduleCount++;
                    break;
                }
            }
        }
        vector<int> ans;
        ans.push_back(jobScheduleCount);
        ans.push_back(totalProfit);
        return ans;
    } 
};