int divisors(int n){
    int count = 0;
    for(int i=1; i<=n; i++){
        if(n%i == 0) count++;
    }
    return count;
}


int divisors(int n){
    int count = 0;
    for(int i=1; i<=sqrt(n); i++){
        if(n%i == 0) count = count + 2;
    }
    return count;
}


int divisors(int n){
    int count = 0;
    for(int i=1; i*i<=n; i++){
        if(n%i == 0) count = count + 2;
    }
    return count;
}

//for perfect suqare condition
void divisors(int n){
    int count = 0;
    int divisorSum = 0;
    for(int i=1; i*i<=n; i++){
        if(n%i == 0){
            count++;
            divisorSum += i;
            if(n/i != i){
                count++;
                divisorSum += n/i;
            }
        }
    }
    cout << count << " " << divisorSum;
}

//O(sqrt(N))

//Question
//Queries - 10 ^ 6

