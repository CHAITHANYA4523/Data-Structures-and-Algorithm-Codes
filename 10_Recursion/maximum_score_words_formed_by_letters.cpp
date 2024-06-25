class Solution {
private:    
    void solve(int i, vector<int> &cnt, vector<int> &score,
    int &ans, int sum, vector<string> &words){
        ans = max(ans, sum);
        if(i >= words.size()) return;
        vector<int> tmp = cnt;
        int j = 0, sum1 = 0;
        for(j = 0; j < words[i].length(); j++){
            tmp[words[i][j]-'a']--;
            sum1 += score[words[i][j]-'a'];
            if(tmp[words[i][j]-'a']<0) break;
        }
        if(j == words[i].length()){
            solve(i+1, tmp, score, ans, sum+sum1, words);
        }
        solve(i+1, cnt, score, ans, sum, words);
    }
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> cnt(26, 0);
        for(int i=0; i<letters.size(); i++){
            cnt[letters[i] - 'a']++;
        }
        int ans = 0, n = words.size();
        solve(0, cnt, score, ans, 0, words);
        return ans; 
    }
};