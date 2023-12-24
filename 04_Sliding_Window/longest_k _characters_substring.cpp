//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    int i = 0, j = 0;
    int maxi = -1;
    unordered_map <char, int> mp;
    while(j< s.length()){
       mp[s[j]]++;
       if(mp.size() < k){
           j++;
       }
       else if(mp.size() == k){
           maxi = max(maxi, j-i+1);
           j++;
       }
       else if(mp.size() > k){
          while(mp.size() > k){
              mp[s[i]]--;
              if(mp[s[i]] == 0){
                  mp.erase(s[i]);
              }
              i++;
          } 
          j++;
       }
    }
    return maxi;
  }
};

/*
Time complexity: O(n)
where n is the size of the input array ‘nums’. This is because each element in ‘nums’ is visited at most twice, once by the ‘j’ pointer (right pointer) and (possibly) once more by the ‘i’ pointer (left pointer).
Space complexity: O(1)
constant space is used. The space does not increase with the size of the input array ‘nums’.
*/