class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<vector<string>> q;
        q.push({beginWord});
        // A vector defined to store the words being currently used
        // on a level during BFS.
        vector<string> usedOnLevel;
        usedOnLevel.push_back(beginWord);
        int level = 0;
        vector<vector<string>> ans;
        while (!q.empty()){
            vector<string> vec = q.front();
            q.pop();
            // Now, erase all words that have been
            // used in the previous levels to transform
            if (vec.size() > level){
                level++;
                for (auto it : usedOnLevel){
                    st.erase(it);
                }
            }
            string word = vec.back();
            if (word == endWord)
            {
                // the first sequence where we reached end
                if (ans.size() == 0){
                    ans.push_back(vec);
                }
                else if (ans[0].size() == vec.size()){
                    ans.push_back(vec);
                }
            }
            for (int i = 0; i < word.size(); i++){   
                char original = word[i];
                for (char c = 'a'; c <= 'z'; c++){
                    word[i] = c;
                    if (st.count(word) > 0)
                    { 
                        // Check if the word is present in the wordList and
                        // push the word along with the new sequence in the queue.
                        vec.push_back(word);
                        q.push(vec);
                        // mark as visited on the level
                        usedOnLevel.push_back(word);
                        // we pop to check for all the strings in the vec 
                        vec.pop_back();
                    }
                }
                word[i] = original;
            }
        }
        return ans;
    }
};

/*
Time Complexity and Space Complexity: It cannot be predicted for this particular algorithm because there can be multiple sequences of transformation from startWord to targetWord depending upon the example, so we cannot define a fixed range of time or space in which this program would run for all the test cases.

Note: This approach/code will give TLE when solved on the Leetcode platform due to the strict time constraints being put up there.
*/