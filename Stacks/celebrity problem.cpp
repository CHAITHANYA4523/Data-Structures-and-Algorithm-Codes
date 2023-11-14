//Function to find if there is a celebrity in the party or not.
    bool knows(vector<vector<int> >& M, int a, int b, int n){
        if(M[a][b] == 1) return true;
        return false;
    }
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> st;
        int n1 = n;
        //push all elements into stack
        for(int i=0; i<n; i++){
            st.push(i);
        }
        
        while(st.size()>1){
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            //if b knows a then a is potential candidate
            if(knows(M, a, b, n)){
                st.push(b);
            }
            //else b is potential candidate
            else st.push(a);
        }
        
        int ans = st.top(); // last remaining potential candidate
        //row check for all zeros
        for(int i=0; i<n; i++){
             if(M[ans][i] != 0) return -1;//not a celbrity
        }
        //col check for all 1's except diagonal elment
        int oneCount = 0;
        for(int i=0; i<n; i++){
             if(M[i][ans] == 1) oneCount++;
        }
        if(oneCount != n-1) return -1;//not a celebrity
        return ans;
        
    }