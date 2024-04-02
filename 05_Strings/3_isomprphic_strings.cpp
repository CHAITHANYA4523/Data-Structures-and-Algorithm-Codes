/*
Anyone facing issue in understanding the description of this question. You must understand the this question needs us to check if there is one directional map exist between given string and a pattern. In the given question, we can treat 's' as given string and 't' as pattern. So, essentially, we have to check if there is a one-directional map exist from 's' to 't'.

Whatever character is there in 's' is not same as in 't'. For instance, s = 'PAPER', t = 'TITLE'. If we can see, character 'E' is common between string 's' and pattern 't'. Character 'E' from string 's' is mapped to character 'L' in pattern 't'. Meanwhile, character 'E' in the pattern 't' is being mapped to character 'R' from string 's'.

string (s)	pattern (t)
   P	         T
   A	         I
   E	         L
   R	         E
So, as long as, character from string 's', have only one map towards character in pattern 't', the strings are isomorphic.
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char,char> mp1;
        unordered_map<char,int> mp2;
        for(int i=0; i<s.size(); i++){
            //to check every character in 's' string is mapped 
            // to only one character in 't'
            if(mp1.count(s[i])){
                if(mp1[s[i]] != t[i]) return false; 
            }
            else{
                mp1[s[i]] = t[i];
                //count the no. of (images of characters in 's')
                //to check multimapping, like two or more characters in 
                // 's' might point to the same character in t
                mp2[t[i]]++;
            }
        }
        for(auto &it:mp2){
            if(it.second > 1) return false;
        }
        return true;
    }
};

//this method also works as we are ensuring all the characters in 's' is mapped to only single character in 't' and vice-versa.

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        //use 2 maps. one for checking the mapping char in s to char in t (s->t) and 
        //another for mapping char in t to char in s (t->s)
        unordered_map<char,char> mp1, mp2;
        for(int i=0; i<s.size(); i++){
            if(mp1.count(s[i])){
                if(mp1[s[i]] != t[i]) return false; 
            }
            else mp1[s[i]] = t[i];
            if(mp2.count(t[i])){
                if(mp2[t[i]] != s[i]) return false; 
            }
            else mp2[t[i]] = s[i];
        }
        return true;
    }
};