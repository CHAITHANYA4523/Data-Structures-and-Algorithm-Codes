class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map <char, int> mp;
        int ans = 0;
        int i = 0, j = 0;
        while(j < s.length()){
            mp[s[j]]++;
            if(mp.size() < j-i+1){
                while(mp.size() < j-i+1){
                    mp[s[i]]--;
                    if(mp[s[i]] == 0){
                        mp.erase(s[i]);
                    }
                    i++;
                }
                j++;
            }
            else if(mp.size() == j-i+1){
                ans = max(ans, j-i+1);
                j++;
            }
            else if(mp.size() > j-i+1){
                j++;
            }
        }
        return ans;
    }
};

/*
Time complexity: O(n)
 where n is the length of the string ‘s’. This is because each character in ‘s’ is visited at most twice, once by the ‘j’ pointer (right pointer) and (possibly) once more by the ‘i’ pointer (left pointer).
Space complexity: O(m)
 where m is the size of the character set. In the worst case, all characters are distinct and stored in the hash map.
*/