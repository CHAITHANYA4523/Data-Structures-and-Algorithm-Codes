#include <bits/stdc++.h>
using namespace std;
int M = 1e9 + 7;
int binaryExpRecur(int a, int b){
    //if power is zero return 1
    if(b == 0) return 1;
    long long result = binaryExpRecur(a, b/2);
    //if power is odd
    if(b&1){
        return (a * (result * result)%M)%M;
    }
    else{
        return (result * result)%M;
    }
}

//iterative approach
/*
take the binary representation of power and when the bit is set 
then update the answer by multiplying the ans with a to the power of
corresponding set bit 
*/
int binaryExpItr(int a, int b){
    int ans = 1;
    while(b){
        if(b&1){
            ans = ans * a;
        }
        a = a * a;
        b = b >> 1;
    }
}

int main(){
    int a, b;
    cin >> a >> b;
    //a power b is calculated
    binaryExpRecur(a, b);
    return 0;
}

/*
Recursive Approach (`binaryExpRecur`)

Time Complexity: O(log b) - The time taken is logarithmic with respect to the exponent 'b' since the function divides 'b' by 2 in each recursive call.

Space Complexity: O(log b) - Due to the recursive nature of the function, it consumes additional space on the call stack proportional to the depth of recursion, which is logarithmic with respect to 'b'.

Iterative Approach (`binaryExpItr`)

Time Complexity: O(log b) - Similar to the recursive approach, the time complexity is logarithmic with respect to 'b' as the while loop iterates 'log b' times, halving 'b' in each iteration.

Space Complexity: O(1) - The iterative approach utilizes constant space regardless of the size of the exponent, as it doesn't rely on recursion and doesn't allocate additional space based on the exponent's magnitude.
*/

// a <= 10^9, b <= 10^9, M <= 10^9

//case: 1) a > 10^9

// a <= 10^9 or 2^1024
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
}

//case: 2) M > 10^9

// M <= 10^18 

//in this case as M = 1e18 + 7 if a = 1e9, 
//after this step a = (a * 1LL * a)%M;  a = 1e18 in next iteration 
//it will overflow with 1e18 * 1e9
long long binaryExp(long long a, long long b){
    int ans = 1;
    while(b > 0){
        if(b&1){
            ans = binMultiply(ans,a)%M;
        }
        a = binMultiply(a,a)%M;
        b = b >> 1;
    }
}

// a*a = a + a + .. + a (a times)
long long binMultiply(long long a, long long b){
    int ans = 0;
    while(b > 0){
        if(b&1){
            ans = (ans + a)%M;
        }
        a = (a + a)%M;
        b = b >> 1;
    }
    return ans;
}

/*Time complexity: log^2(n) (log square n).
log(n) for binaryExp and n for binMultiply function
*/
