//Approach
/*
This approach uses bfs traversal because we go on replacing the characters one by one which seems just like we’re moving level-wise in order to reach the destination i.e. the targetWord.
take each word and change each letter of word and compare it with words in wordList and count steps.
use a set to remove already visited words in the wordList.
*/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        q.push({beginWord, 1});
        unordered_set<string> s(wordList.begin(), wordList.end());
        s.erase(beginWord);
        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
             // we return the steps as soon as
            // the first occurence of targetWord is found.
            if(word == endWord) return steps;
            for(int i=0; i<word.length(); i++){
                char original = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++){
                    word[i] = ch;
                    if(s.find(word) != s.end()){
                        s.erase(word);
                        q.push({word, steps+1});
                    }
                }
                //replace the character with orginal char otherwise 'z' will occupy that place
                word[i] = original;
            }
        }
        //if endWord is not found.
        return 0;
    }
};

/*
Time Complexity: O(N * M * 26)
Where N = size of wordList Array and M = word length of words present in the wordList..
Note that, hashing operations in an unordered set takes O(1) time, but if you want to use set here, then the time complexity would increase by a factor of log(N) as hashing operations in a set take O(log(N)) time.

Space Complexity:  O( N ) { for creating an unordered set and copying all values from wordList into it } Where N = size of wordList Array.
*/