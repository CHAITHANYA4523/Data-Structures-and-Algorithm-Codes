#include <bits/stdc++.h>
using namespace std;

const int N = 1e7+10;
//Q < 10^7, N < 10^7 

vector<int> isPrime(N, 1);


int main(){
    isPrime[0] = isPrime[1] = false;
    for(int i=2; i<N; i++){
        if(isPrime[i] == true){
            for(int j=2*i; j < N; j += i){
                isPrime[j] = false;
            }
        }
    }
    //n*(log(log(n)))

    int q;
    cin >> q;
    while(q--){
        int num; 
        cin >> num;
        if(isPrime[num]) cout << "prime" << endl;
        else cout << "not prime" << endl;
    }
    //Q*(O(1))


    //sieve variations

    //highest prime factor of the number
    vector<int> hp(N, 0);
    for(int i=2; i<N; i++){
        if(isPrime[i] == true){
            lp[i] = hp[i] = i;
            for(int j=2*i; j < N; j += i){
                isPrime[j] = false;
                hp[j] = i;
            }
        }
    }


    //lowest prime factor of the number
    vector<int> lp(N, 0);
    for(int i=2; i<N; i++){
        if(isPrime[i] == true){
            lp[i] = hp[i] = i;
            for(int j=2*i; j < N; j += i){
                isPrime[j] = false;
                hp[j] = i;
                if(lp[j] == 0){
                    lp[j] = i;
                }
            }
        }
    }

    //finding prime factors of a number
    int num;
    cin >> num;
    vector<int> primeFactors;
    while(num > 1){
        int primeFactor = hp[num];
        while(num 5 primeFactor == 0){
            num = num/primeFactor;
            primeFactors.push_back(primeFactor);
        }
    }
    //O(log(N))

    //storing all multiples
    vector<int> multiples[N];
    for(int i=2; i<N; i++){
        for(int j = i; j < N; j += i){
            divisors[j].push_back(i);
        }
    }

}

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(366 + 30, INT_MAX);
        dp[0] = 0;
        for (int day : days) dp[day] = 0;
        for (int i = 1; i < 366 + 30; ++i) {
            if (dp[i] == INT_MAX) dp[i] = dp[i - 1];
            else dp[i] = min({costs[0] + dp[i - 1], costs[1] + dp[max(0, i - 7)], costs[2] + dp[max(0, i - 30)]});
        }
        return dp[days.back()];
    }
};


