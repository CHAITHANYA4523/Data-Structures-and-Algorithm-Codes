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

/*
The time complexity of this function is O(n), where n is the size of the array. This is because there are two for loops that each run n times, but they are not nested, so they do not multiply together.

The space complexity of this function is also O(n). This is because a new vector v of size n is created to hold the rotated array. The rest of the variables use a constant amount of space.
*/