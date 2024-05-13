#include <bits/stdc++.h>
using namespace std;

int binaryExp(int a, int b){
    a = binExp(a, b);
    int ans = 1;
    while(b > 0){
        if(b&1){
            ans = (ans * 1LL * a)%M;
        }
        a = (a * 1LL * a)%M;
        b = b >> 1;
    }
    return ans;
}

int main(){
    int a;
    cin >> a;
    //a inverse
    binexp(a, M-2, M);    
}