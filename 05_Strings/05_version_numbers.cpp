class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0;
        stringstream ss1(version1), ss2(version2); 
        string s;
        while(i < version1.size() && j < version2.size()){
            getline(ss1, s, '.');
            i += s.size() + 1;
            long long first = stoll(s);
            getline(ss2, s, '.');
            j += s.size() + 1;
            long long second = stoll(s);
            if(first < second) return -1;
            else if(first > second) return 1;
        }
        while(i < version1.size()){
            getline(ss1, s, '.');
            i += s.size() + 1;
            long long val = stoll(s);
            if(val > 0) return 1;
        }
        while(j < version2.size()){
            getline(ss2, s, '.');
            j += s.size() + 1;
            long long val = stoll(s);
            if(val > 0) return -1;
        }
        return 0;
    }
};

/*
Let's update the time complexity analysis considering the time complexity of the `getline` function.

### Time Complexity:
1. **String Stream Initialization:** Constructing the string streams `ss1` and `ss2` has a time complexity of O(n), where n is the size of `version1` and `version2`.
  
2. **While Loop (Comparison):** In the while loop, `getline` is called until either `version1` or `version2` is exhausted. Each call to `getline` has a time complexity proportional to the length of the substring being read, denoted as k. Since there are potentially m segments in each version, where m is the maximum number of segments between the two versions, the time complexity of this loop is O(m * k).

3. **While Loops (Remaining Characters):** After the comparison loop, there are two more while loops that handle the remaining segments in `version1` and `version2`, if any. The time complexity of each of these loops depends on the number of remaining segments and the average length of each segment.

Overall, the time complexity of the function is O(n + m * k + p * k), where n is the size of the input strings, m is the maximum number of segments, k is the average length of each segment, and p is the number of remaining segments.

### Space Complexity:
1. **String Streams:** Creating the string streams `ss1` and `ss2` requires additional space proportional to the lengths of `version1` and `version2`, which is O(n).

2. **Other Variables:** The space used by other variables like `i`, `j`, and `s` is constant and doesn't depend on the input size.

Overall, the space complexity remains O(n).

In summary:
- Time complexity: O(n + m * k + p * k)
- Space complexity: O(n)
*/