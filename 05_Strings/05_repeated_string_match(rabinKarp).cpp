class Solution {
private:
    int BASE = 100000;
public:
    int repeatedStringMatch(string a, string b) {
        if(a == b) return 1;
        //string itself is considered as one repetition
        int cnt = 1;
        string source = a;
        while(source.size() < b.size()){
            cnt++;
            source += a;
        }
        if(source.find(b) != string::npos) return cnt;  
        source += a;
        if(source.find(b) != string::npos) return cnt + 1;  
        return -1;
    }

    int rabinKarp(string& source, string& pattern) {
        long long p = 31, M = 1e9 + 9;
        int n = source.size(), m = pattern.size();
        
        vector<long long> power(max(n, m), 1);
        for(int i = 1; i < power.size(); i++){
            power[i] = (power[i-1]*p) % M;
        }
        
        vector<long long> sourceHashCode(n + 1, 0);
        for(int i = 0; i < n; i++){
            sourceHashCode[i+1] = (sourceHashCode[i] + (source[i]-'a'+1)*power[i])%M;
        }
        
        long long patternHashCode = 0;
        for(int i = 0; i < m; i++){
            patternHashCode = (patternHashCode + (pattern[i]-'a'+ 1)*power[i])%M;
        }
        
        for(int i = 0; i + m <= n; i++){
            long long currHashCode = (sourceHashCode[i + m] - sourceHashCode[i] + M) % M;
            if(currHashCode == (patternHashCode * power[i]) % M) {
                if(source.substr(i, m) == pattern) 
                    return i;
            }
        }
        return -1;
    }
};

/*
Consider a = "abcd" and b = "cdabcdab".

Initial Repetitions:
After repeating a twice (abcdabcd), the length of the repeated string becomes 8, which is greater than the length of b (8). However, b ("cdabcdab") is not a substring of abcdabcd.

Adding One More a:
After repeating a one more time (abcdabcdabcd), the length becomes 12. Now, b ("cdabcdab") is a substring of abcdabcdabcd, starting from the third character.
Why One More Repetition is Necessary:
In this case, the tail of the first repetition of a overlaps with the head of the second repetition. For example, the substring "cd" at the end of the first abcd matches with the "cd" at the beginning of b. To fully match b, we need to extend a by adding one more repetition.

General Reasoning:
Partial Matches: If b starts matching with the end of a repeated version of a, it will need one more repetition of a to complete the match.
Ensuring Coverage: By adding one more repetition, we ensure that any overlap between repetitions of a and b is covered.
*/