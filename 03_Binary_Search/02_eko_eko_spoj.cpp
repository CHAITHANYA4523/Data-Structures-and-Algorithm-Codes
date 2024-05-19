#include <bits/stdc++.h>
using namespace std;
 
long long maxFunction(vector<long long> &arr, long long n){
    long long maxi = INT_MIN;
    for(int i=0; i<n; i++){
        maxi = max(maxi, arr[i]);
    }
    return maxi;
}
long long optimal(vector<long long> &arr, int mid){
    long long sum = 0;
    for(int i=0; i<arr.size(); i++){
        if(arr[i] > mid){
            sum += arr[i] - mid;
        }
    }
    return sum;
}
int main() {
    long long n, m;
    cin >> n >> m;
    vector<long long> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    } 
    sort(arr.begin(), arr.end());
    long long low = 0, high = maxFunction(arr, n);
    long long ans = 0;
    while(low <= high){
        int mid = low + (high-low)/2;
        long long totalMeters = optimal(arr, mid);
        if(totalMeters >= m){
            ans = mid;
            low = mid+1;
        }
        else high = mid-1;
    }
    cout << ans << endl;
    return 0;
}
 