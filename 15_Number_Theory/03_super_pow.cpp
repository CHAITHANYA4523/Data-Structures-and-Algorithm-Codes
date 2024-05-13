class Solution {
private:
    int binExp(int a, long long b, int m){
        int ans = 1;
        while(b > 0){
            if(b&1){
                ans = (ans * 1LL * a)%m;
            }
            a = (a * 1LL * a)%m;
            b = b >> 1;
        }
        return ans;
    }
public:
    int superPow(int a, vector<int>& b) {
        int phi = 6*190; //using euler totient theorem (1337 is not prime(7*191))
        int pwr = 0;
        long long m = 1;
        for(int i=b.size()-1; i>=0; i--){
            pwr += (b[i]*m)%phi;
            m = (m*10)%phi;
        }
        cout << pwr << endl;
        int ans = binExp(a, pwr, 1337);
        return ans;
    }
};

