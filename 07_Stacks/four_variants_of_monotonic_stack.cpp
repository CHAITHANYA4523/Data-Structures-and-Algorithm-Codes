//Next Greater Element to Right
vector<long long> nextGreaterElement(vector<long long> &arr, int n){
    stack<long long> st;
    vector<long long> nge(n);
    for(int i = n-1; i >= 0; i--){
        while(!st.empty() && st.top() <= arr[i]){
            st.pop();
        }
        if(!st.empty()) nge[i] = st.top();
        else nge[i] = -1;
        st.push(arr[i]);
    }
    return nge;
}

//Next Smaller Element to Right
vector<long long> nextSmallerElementRight(vector<long long> &arr, int n){
    stack<long long> st;
    vector<long long> nse(n);
    for(int i = n-1; i >= 0; i--){
        while(!st.empty() && st.top() >= arr[i]){
            st.pop();
        }
        if(!st.empty()) nse[i] = st.top();
        else nse[i] = -1;
        st.push(arr[i]);
    }
    return nse;
}

//Next Greater Element to Left
vector<long long> nextGreaterElementLeft(vector<long long> &arr, int n){
    stack<long long> st;
    vector<long long> nge(n);
    for(int i = 0; i < n; i++){
        while(!st.empty() && st.top() <= arr[i]){
            st.pop();
        }
        if(!st.empty()) nge[i] = st.top();
        else nge[i] = -1;
        st.push(arr[i]);
    }
    return nge;
}

//Next Smaller Element to Left
vector<long long> nextSmallerElementLeft(vector<long long> &arr, int n){
    stack<long long> st;
    vector<long long> nse(n);
    for(int i = 0; i < n; i++){
        while(!st.empty() && st.top() >= arr[i]){
            st.pop();
        }
        if(!st.empty()) nse[i] = st.top();
        else nse[i] = -1;
        st.push(arr[i]);
    }
    return nse;
}
