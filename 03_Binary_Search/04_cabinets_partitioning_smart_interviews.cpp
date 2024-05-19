/*
Cabinets Partitioning 

You are given a job that has been divided into N tasks. The task cannot be divided any further. Each of the N tasks takes Si number of seconds to complete. Your job will be completed when all your tasks are completed. You have K workers at your disposal to help you complete the tasks. But as per the nature of the job, a worker can only be allocated continuous tasks. A worker can work only on a single task at any given point in time. However, the workers can work in parallel on different tasks. You have to find the minimum possible time in which you can complete the job.

Constraints
1 <= N,K <= 10000

General Constraints
1 <= T <= 50
1 <= Si <= 103

Example
Input
6
10 3
1 10 13 4 5 12 23 12 18 8
8 4
17 27 22 45 26 32 45 16
2 2
74 61
7 3
74 24 61 81 66 76 51
2 1
54 10
4 2
15 30 10 50

Output
38
66
74
159
64
55

Explanation
Test Case 1: The arrangement for which we can achieve minimum possible time is as follows:
[1 10 13 4 5] - Worker 1
[12 23] - Worker 2
[12 18 8] - Worker 3

Test Case 2: The arrangement for which we can achieve minimum possible time is as follows:
[17 27 22] - Worker 1
[45] - Worker 2
[26 32] - Worker 3
[45 16] - Worker 4
*/

#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &task, int workerLimit, int timeLimit){
    int currTime = 0;
    int workerCount = 1;
    for(int i=0; i<task.size(); i++){
        if(currTime + task[i] <= timeLimit){
            currTime += task[i];
        }
        else{
            workerCount++;
            currTime = task[i];
            if(workerCount > workerLimit) return false;
        } 
    }
    return true;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> task(n);
        int sum = 0, maxi = INT_MIN;
        for(int i=0; i<n; i++){
            cin >> task[i];
            maxi = max(maxi, task[i]);
            sum += task[i];
        } 
        int low = maxi, high = sum, ans = sum;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(isPossible(task, k, mid)){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        cout << ans << endl;
    }
    return 0;
}