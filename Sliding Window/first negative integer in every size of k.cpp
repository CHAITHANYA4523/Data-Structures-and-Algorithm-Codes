
//Approach with deque
vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
    deque <long long int> dq;
    vector <long long> ans;
    
    // process first window of k size
    for(int  i=0; i<K; i++){
        if(A[i]<0){
            dq.push_back(i);
        }
    }
    // store size of first k sized window
    if(dq.size()>0){
       ans.push_back(A[dq.front()]);
    }
    else{
        ans.push_back(0);
    }
    // process for remaining windows
    for(int i=K; i<N; i++){
        // removal
        if(!dq.empty() && i-dq.front() >=K){
            dq.pop_front();
        }
        // addition
        if(A[i]<0){
            dq.push_back(i);
        }
        // ans store
         if(dq.size()>0){
       ans.push_back(A[dq.front()]);
       }
     else{
        ans.push_back(0);
      }
    }
    return ans; 
 }

 /*
 **Time Complexity (O(N)):**
The code processes each element in the array once, and both the addition and removal from the deque take constant time. The for loop runs for N iterations, resulting in a linear time complexity, where N is the size of the input array.

**Space Complexity (O(K)):**
The deque `dq` stores at most K elements at any given time, representing the window size. Therefore, the space complexity is O(K), where K is the given window size. Additionally, the vector `ans` stores the result for each window, adding a constant amount of space. Overall, the space complexity is dominated by the deque size, resulting in O(K).
 */

//Approach with vector 
vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
    long long int i=0,j=0;
    vector<long long> v;
    vector<long long> ans;
    while(j < N){
        if(A[j] < 0){
            v.push_back(A[j]);
        }
        if(j-i+1 < K){
            j++;
        }
        else if(j-i+1 == K){
            if(v.size() == 0){
                ans.push_back(0);
            }
            else{
               ans.push_back(v.front());
               if(A[i] == v.front()){
                   v.erase(v.begin());
               }
            }
            i++;
            j++;
        }
    }
    return ans;
    
}