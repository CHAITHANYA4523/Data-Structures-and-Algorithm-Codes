class Solution {
public:
    string reverseParentheses(string s){
        stack<string> st;
        string current;
        for (char c : s) {
            if (c == '(') {
                st.push(current);
                current = "";
            } else if (c == ')') {
                reverse(current.begin(), current.end());
                current = st.top() + current;
                st.pop();
            } else {
                current += c;
            }
        }
        return current;
    }
};

// https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/solutions/382421/JavaPython-3-Iterative-short-codes-w-comment-and-analysis