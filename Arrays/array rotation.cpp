vector<int> rotateArray(vector<int>&a, int x, string dir) {
    vector<int> v(a.size());
    string l="LEFT";
    string r="RIGHT";
    int n=a.size();
    x = x%n;
    if(dir==l){
        for(int i=0; i<n; i++){
            v[(i+n-x)%n]=a[i];
        }
        a = v;
    }
    if(dir == r){
        for(int i=0; i<n; i++){
            v[(i+x)%n] = a[i]; 
        }
        a = v;
    }
    return a;
}