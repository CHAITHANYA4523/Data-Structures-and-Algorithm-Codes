#include <bits/stdc++.h>
using namespace std;

int main(){
    bool isPrime = true;
    int n;
    cin >> n;
    for(int i=2; i<n; i++){
        if(n%i == 0) {
            isPrime = false;
            break;
        }
    }
    //O(N)
    cout << isPrime;


    bool isPrime = true;
    int n;
    cin >> n;
    for(int i=2; i*i<=n; i++){
        if(n%i == 0) {
            isPrime = false;
            break;
        }
    }
    //O(sqrt(N))
    cout << isPrime;

/*
smallest divisor of any number is a prime number (excluding 1).
*/

    vector<int> primeFactors;
    for(int i=2; i<=n; i++){
        while(n%i == 0){
            primeFactors.push_back(i);
            n = n/i;
        }
    }
    //O(N)


    vector<int> primeFactors;
    for(int i=2; i*i<=n; i++){
        while(n%i == 0){
            primeFactors.push_back(i);
            n = n/i;
        }
    }
    //if a single prime is left for loop won't run
    if(n > 1) primeFactors.push_back(n);
    //O(sqrt(N))
}



