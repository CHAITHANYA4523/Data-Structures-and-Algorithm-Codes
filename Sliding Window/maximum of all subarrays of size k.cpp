vector<int> Solution::slidingMaximum(const vector<int> &arr, int k){
       deque<int>q;
        int i=0,j=0;
        vector<int>res;
        while(j<arr.size()){
            while(!q.empty() && q.back()<arr[j]) q.pop_back();
            q.push_back(arr[j]);
            if(j-i+1<k) j++;
            else if(j-i+1==k){
                res.push_back(q.front());
                if(q.front()==arr[i]) q.pop_front();
                i++;
                j++;
            }
        }
        return res;
}   

/*
Time Complexity: O(N)
The code utilizes a sliding window approach with two pointers (i and j) to iterate through the input array (arr). The while loop runs for each element of the array once, and the operations within the loop are constant time. Therefore, the time complexity is linear, O(N), where N is the size of the input array.

Space Complexity: O(K)
The space complexity is determined by the size of the deque (q), which stores at most K elements at any given time, representing the window size. Therefore, the space complexity is O(K), where K is the given window size. Additionally, the vector res stores the result for each window, adding a constant amount of space. Overall, the space complexity is dominated by the deque size, resulting in O(K).
*/