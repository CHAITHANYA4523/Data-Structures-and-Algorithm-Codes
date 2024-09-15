class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_set<char> vowels;
        vowels.insert('a');
        vowels.insert('e');
        vowels.insert('i');
        vowels.insert('o');
        vowels.insert('u');
        map<int,int> bitmaskMap;
        //when no character is considered (even vowels are present) 
        //which points to -1 index
        bitmaskMap[0] = - 1;
        int ans = 0;
        int mask = 0;
        for(int i = 0; i < s.length(); i++){
            char ch = s[i];
            if(vowels.count(ch)){
                int val = (ch - 'a') + 1;
                mask = mask ^ val;
            }
            //if mask is present in the map check if 
            //it is a possible answer
            if(bitmaskMap.find(mask) != bitmaskMap.end()){
                ans = max(ans, i - bitmaskMap[mask]);
            }
            //if mask is not present in the map add it to the map
            else{
                bitmaskMap[mask] = i;
            }
        }
        return ans;
    }
};

//https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/description/?envType=daily-question&envId=2024-09-15