//brute force
long long max_sum(int a[], int n) {
        if(n == 1) return 0;
        int ans = 0;
        for(int i = 0; i < n; i++){
            int curr = 0;
            for(int j = 0; j < n; j++){
                int idx = (i + j) % n;
                curr += j * a[idx];
            }
            ans = max(ans, curr);
        }
        return ans;
}

//optimised
long long max_sum(int a[], int n) {
        if(n == 1) return 0;
        long long currSum = 0;
        long long currAns = 0;
        vector<long long> arr(n);
        for(int i = 0; i < n; i++) arr[i]= a[i];
        for(int i = 0; i < n; i++) currSum += arr[i];
        for(int i = 0; i < n; i++) currAns += i * arr[i];
        long long ans = currAns;
        for(int i = 1; i < n; i++){
            long long nextAns = currAns - (currSum - arr[i - 1]) 
            + (arr[i - 1] * (n - 1));
            currAns = nextAns;
            ans = max(ans, currAns);
        }
        return ans;
}