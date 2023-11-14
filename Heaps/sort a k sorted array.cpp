vector <int> nearlySorted(int arr[], int num, int K){
    priority_queue<int, vector<int>, greater<int>> minHeap;
    vector<int> ans;
    for(int i=0; i<num; i++){
        minHeap.push(arr[i]);
        if(minHeap.size() > K){
            ans.push_back(minHeap.top());
            minHeap.pop();
        }
    }
    while(!minHeap.empty()){
        ans.push_back(minHeap.top());
        minHeap.pop();
    }
    return ans;
}