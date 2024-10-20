string smallestWindow (string s, string p){
    if(p.size() > s.size()) return "-1";
    unordered_set<char> st(p.begin(), p.end());
    vector<int> cnt1(26, 0);
    vector<int> cnt2(26, 0);
    for(auto ch : p) cnt1[ch - 'a']++;
    int i = 0, j = 0;
    int k = st.size();
    pair<int, int> ans;
    int mini = INT_MAX;
    while(j < s.size()){
        char curr = s[j];
        cnt2[curr - 'a']++;
        if(cnt2[curr - 'a'] == cnt1[curr - 'a']){
            k--;
        }
        while(k == 0){
            if(mini > j - i + 1){
                mini = j - i + 1;
                ans.first = i;
                ans.second = mini;
            }
            char start = s[i];
            cnt2[start - 'a']--;
            if(cnt1[start - 'a'] > 0){
                if(cnt2[start - 'a'] < cnt1[start - 'a']){
                    k++;
                }
            }
            i++;
        }
        j++;
    }
    if(mini == INT_MAX) return "-1";
    return s.substr(ans.first, ans.second);
}

// https://www.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1