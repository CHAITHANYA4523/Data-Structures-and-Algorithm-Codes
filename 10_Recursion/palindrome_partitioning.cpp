class Solution {
private:
    bool isPalindrome(string s, int start, int end){
        while(start <= end){
            if(s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
    void solve(string s, vector<string> &path, vector<vector<string>> &res, int i){
        if(i == s.size()){
            res.push_back(path);
            return;
        }
        for(int idx=i; idx<s.size(); idx++){
            if(isPalindrome(s, i, idx)){
                path.push_back(s.substr(i, idx-i+1));
                solve(s, path, res, idx+1);
                path.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        solve(s, path, res, 0);
        return res;
    }
};