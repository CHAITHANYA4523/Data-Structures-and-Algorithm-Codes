//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    unordered_map<char,int> mp;
	    int ans = 0;
	    for(int i=0; pat[i] != '\0'; i++){
	        mp[pat[i]]++;
	    }
	    int k = pat.length();
	    int n = txt.length();
	    int count = mp.size();
	    int i = 0, j = 0;
	    while(j < n){
	        // reduce the frequency of the value at jth index
    	    if (mp.find(txt[j]) != mp.end()){
                    mp[txt[j]]--;
                    if (mp[txt[j]] == 0){
                        count--;
                }
            }
	        if(j-i+1 < k){
	            j++;
	        }
	        else if(j-i+1 == k){
	            if(count == 0){
	                ans++;
	            }
	            // add the frequency of ith index back
	            if (mp.find(txt[i]) != mp.end()){
                    mp[txt[i]]++;
                    if (mp[txt[i]] == 1){
                        count++;
                    }
                }
	            i++;
	            j++;
	        }
	    }
	    return ans;
	}

};

/*
Time Complexity: O(N)
The code uses a sliding window approach with two pointers (i and j) to iterate through the text (txt) once. The while loop runs for each character of the text once, and within the loop, the operations are constant time. Therefore, the time complexity is linear, O(N), where N is the length of the input text.

Space Complexity: O(M)
The space complexity is determined by the size of the unordered_map mp, where M is the number of unique characters in the pattern (pat). In the worst case, the size of mp could be equal to the size of the character set. Therefore, the space complexity is O(M).
*/