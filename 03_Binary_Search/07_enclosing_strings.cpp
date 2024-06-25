#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<int> &cntA, vector<int> cntB){
    for(int i=0; i<26; i++){
        if(cntB[i] < cntA[i]) return false;
    }
    return true;
}

bool isPossible(string &s2, int mid, vector<int> &cntA, 
vector<int> cntB){
    int i = 0, j = 0;
    while(j < s2.size()){
        cntB[s2[j]-97]++;
        while(j-i+1 > mid){
            cntB[s2[i]-97]--;
            i++;
        }
        if(j-i+1 == mid){
            if(isValid(cntA, cntB)) return true;
        }
        j++;
    }
    return false;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin >> t;
    while(t--){
        string s1, s2;
        cin >> s1 >> s2;
        vector<int> cntA(26, 0);
        for(int i=0; i<s1.size(); i++) cntA[s1[i]-97]++;
        vector<int> cntB(26, 0);
        int ans = -1;
        int low = s1.size(), high = s2.length();
        while(low <= high){
            int mid = low + (high-low)/2;
            if(isPossible(s2, mid, cntA, cntB)){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        cout << ans << endl;
    }
    return 0;
}

// https://hive.smartinterviews.in/contests/smart-interviews-primary/problems/enclosing-substring