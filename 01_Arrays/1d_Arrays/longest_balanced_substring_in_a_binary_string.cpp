class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int ans = 0;
        for(int i=0; i<s.length();){
            int zeroes = 0;
            int ones = 0;
            while(i<s.length() && s[i] == '0'){
                zeroes++;
                i++;
            }
            while(i<s.length() && s[i] == '1'){
                ones++;
                i++;
            }
            //if no zeroes or ones occured len becomes zero
            int len = 2 * min(zeroes, ones);
            ans = max(ans, len);
        }
        return ans;
    }
};