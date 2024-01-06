class Solution {
public:
    string longestPalindrome(string s) {
        int k, l;
        int maxLength = 0;
        string subString;
        for(int i=0; i<s.size(); i++){
            for(int j=s.size()-1; j>= i; j--){
                if(s[i] == s[j]){
                    k = i;
                    l = j;
                    bool counter = true;
                    while(k <= l){
                        if(s[k++] != s[l--]){
                            counter = false;
                            break;
                        }
                    }
                    if(j-i+1 > maxLength && counter){
                        maxLength = j-i+1;
                        subString = s.substr(i, maxLength);
                    }
                }
            }
        }
        return subString;
    }
};

/*
Time Complexity:
The nested loops iterate through all pairs of indices (i, j) in the input string s, where i and j are the starting and ending indices of potential substrings. For each pair, there is a while loop that checks whether the substring is a palindrome or not. The maximum number of iterations in the worst case would be O(n^3), where 'n' is the length of the input string.
*/