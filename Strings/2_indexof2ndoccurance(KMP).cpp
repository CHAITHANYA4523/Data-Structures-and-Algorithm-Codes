//brute force solution
class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        for (int i = 0; i < m-n+1; i++) {
            int j = 0;
            for (; j < n; j++) {
                if (haystack[i + j] != needle[j]) {
                    break;
                }
            }
            if (j == n) {
                return i;
            }
        }
        return -1;
    }
};

class Solution {
public:
    // Function to calculate the Longest Prefix Suffix (LPS) array
    vector<int> buildLPS(string pattern) {
        int m = pattern.length(); // Find pattern length
        vector<int> lps(m, 0);  // Declare lps array
        int i = 1;  // Init forward pointer
        int j = 0;  // Init backward pointer
        while (i < m) {
            if (pattern[i] == pattern[j]) {  // If forward equals backward
                lps[i] = j + 1;  // The current character at forward can also lead to the next backward character 
                i++;  // Go to the next forward
                j++;  // Go to the next backward
            } else { // If forward does not equal backward
                if (j != 0) {  // If the length of the prefix isn't zero, we go to the previous backward prefix of the same character
                    j = lps[j - 1];
                } else {  // Else if j equals zero, i.e., if there is no prefix
                    lps[i++] = 0;  // Assign the corresponding length and go to the next forward
                }
            }
        }
        return lps;
    }
    
    // Function to perform string searching using KMP algorithm
    int strStr(string haystack, string needle) {
        int n = haystack.length(), m = needle.length(); // Get lengths of haystack and needle
        if (m == 0) return 0; // If needle is empty, return 0
        vector<int> lps = buildLPS(needle); // Compute LPS array for the needle
        int i = 0, j = 0; // Initialize indices i and j
        while (i < n && j < m) { // Iterate through haystack and needle
            if (haystack[i] == needle[j]) { // If characters match, increment both i and j
                i++;
                j++;
            } 
            if (j == m) return i - j; // If the entire needle is found, return the starting index  
            else if (i < n && j < m && haystack[i] != needle[j]) {
                if (j) {
                    j = lps[j - 1]; // Update j based on the LPS array
                } else {
                    i++; // If no match found and j is already 0, increment i
                }
            }
        }
        return -1; // If the needle is not found in the haystack, return -1
    }
};
