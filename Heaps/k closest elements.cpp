class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        //we use maxHeap because numbers with greater difference are to be excluded that come on top 
        priority_queue<pair<int, int>> maxHeap;
        vector<int> v;
        for(int i=0; i<arr.size(); i++){
            //sorting occurs based on first element in pairs
            maxHeap.push(make_pair(abs(arr[i]-x), arr[i]));
            if(maxHeap.size() > k) maxHeap.pop();
        }
        while(!maxHeap.empty()){
            v.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        sort(v.begin(), v.end());
        return v;
    }
};

//Time complexity - O(n*log k) where n is the size of array and log k for pushing and popping the element on the heap (element is added at leaf node and shifted to correct position)
//Space Complexity - O(k) for storing in heap(same no. of elements are stored in vector)