/*
Approach to solve this problem....

1) Initialize leftMin and leftMax to 0.
2) Iterate through each character in the string s.
3) If the character is '(', increment both leftMin and leftMax by 1.
4) If the character is ')', decrement both leftMin and leftMax by 1.
5) If the character is '*', decrement leftMin by 1 and increment leftMax by 1.
6) If leftMax becomes negative at any point, return False since it means there are more closing parentheses than opening ones.
7) If leftMin becomes negative, reset it to 0 since we can't have negative open parentheses count.
After iterating through the string, check if leftMin is 0. If it is, return True; otherwise, return False.
*/

class Solution {
public:
    bool checkValidString(string s) {
        int minDepth = 0;
        int maxDepth = 0;
        for(int i=0; i<s.length(); i++){
            if(s[i] == '('){
                minDepth++;
                maxDepth++;
            }
            else if(s[i] == '*'){
                minDepth--;
                maxDepth++;
            }
            else{
                minDepth--;
                maxDepth--;
            }
            if(maxDepth < 0) return false;
            if(minDepth < 0) minDepth = 0;
        }
        //more left paranthesis
        if(minDepth == 0) return true;
        return false;
    }
};