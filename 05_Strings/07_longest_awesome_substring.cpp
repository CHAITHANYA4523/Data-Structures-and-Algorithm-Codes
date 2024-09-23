class Solution {
public:
    int longestAwesome(string s) {
        map<int, int> bitMaskMap;
        bitMaskMap[0] = -1;
        int mask = 0;
        int ans = 1;
        for(int i = 0; i < s.length(); i++){
            int digit = s[i] - '0';
            mask = mask ^ (1 << digit);
            if(bitMaskMap.find(mask) == bitMaskMap.end()){
                bitMaskMap[mask] = i;
            }
            else ans = max(ans, i - bitMaskMap[mask]);
            if(mask == 0 || __builtin_popcount(mask) == 1) ans = max(ans, i + 1);
            //when one character is odd present in middle of palindrome and remaining are even
            for(int digit = 0; digit <= 10; digit++){
                int newMask = mask ^ (1 << digit);
                if(bitMaskMap.find(newMask) != bitMaskMap.end()){
                    ans = max(ans, i - bitMaskMap[newMask]);
                }
            }
        }
        return ans;
    }
};