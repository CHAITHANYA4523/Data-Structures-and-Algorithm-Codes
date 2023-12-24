//brute force approach (Approach 1)
class Solution{
public:
	int isRotatedPalindrome(string s)
	{
	    int n = s.length(),ans = -1;
	    for(int i=0; i<s.length(); i++){
	        int left = i;
	        int right = (i+1)%n;
	        while(left != right){
	            if(s[left] != s[right]){
	                ans = -1;
	                break;
	            }
	            else ans = 1;
	            left = (n+left-1)%n;
	            right = (right+1)%n;
	            if(left == right) ans = 1;
	        }
	        if(ans == 1) return 1;
	    }
	    return ans;
	}
}

//Longest panlindromic suffix (Approach 2) similar to longest palindromic substring


//edge cases
