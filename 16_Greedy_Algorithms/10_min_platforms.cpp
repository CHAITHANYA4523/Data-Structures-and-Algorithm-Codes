class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n){
        
        sort(arr, arr+n);
        sort(dep, dep+n);
        int maxPlatforms = 1, neededPlatforms = 1, i = 1, j = 0;
        while(j < n && i < n){
            if(arr[i] > dep[j]){
                j++;
                maxPlatforms--;
            }
            else if(arr[i] <= dep[j]){
                i++;
                maxPlatforms++;
                if(maxPlatforms > neededPlatforms) neededPlatforms = maxPlatforms;
            }
        }
        return neededPlatforms;
    }
};

//O(n + n*long(n))