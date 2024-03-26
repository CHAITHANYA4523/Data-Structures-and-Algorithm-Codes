class Solution{
public:
    bool isAdditiveSequence(string s) {
        int n = s.length();
        if(n <= 2) return false;
        //length of target can be 1 more than the prev1 and prev2
        int prev1 = 0;
        for(int i=0; i<n/2; i++){
            prev1 = prev1*10 + (s[i]-'0');
            //last index can be target
            int prev2 = 0;
            for(int j=i+1; j<n-1; j++){
                prev2 = prev2*10 + (s[j]-'0');
                int target = 0;
                int k;
                for(k=j+1; k<n; k++){
                    target = target*10 + (s[k]-'0');
                    if(target == prev1 + prev2){
                        prev1 = prev2;
                        prev2 = target;
                        //create new target from scratch
                        target = 0;
                    }
                }
                //if everthing goes fine k will be at come out of the string and
                //target will be set to zero
                if(k == n && target == 0) return true;
            }
        }
        return false;
    }
};

//leetcode solution
//using recursion and checking for cases where the number start with 0. Ex:- 023

class Solution {
private:
    bool helper(long long n1, long long n2, string str, bool found){
        //if the conditions are satisfied till the end
        //that means found will be true and no string will be left 
        //to compare for the last number
        if(str.length() == 0 && found){
            return true;
        }
        string n3 = to_string(n1+n2);
        int idx = min(str.length(), n3.length());
        if(str.substr(0, idx) == n3){
            //update the numbers and take new string from index and mark 
            //found as true
            return helper(n2, stol(n3), str.substr(idx), true);
        }
        return false;
    }
public:
    bool isAdditiveNumber(string s) {
        int n = s.length();
        if(n <= 2) return false;
        for(int i=1; i<n-1; i++){
            //it gives a number in the substring starting at index 0 and
            //take upto i characters 
            long long n1 = stol(s.substr(0, i));
            //to check numbers starting with 0s ex: 023
            //here we compare 23 == 023 which is wrong
            if(to_string(n1) != s.substr(0, i)) break;
            for(int j=i+1; j<n; j++){
                long long n2 = stol(s.substr(i, j-i));
                if(to_string(n2) != s.substr(i, j-i)) break;
                //s.substr(j) starts at j and goes till the last character
                bool found = helper(n1, n2, s.substr(j), false);
                if(found == true) return true;
            }
        }
        return false;
    }
};

/*
The time complexity of the given code is O(n^3) and the space complexity is O(n).

Time Complexity: The outer loop runs n times, where n is the length of the string. For each iteration of the outer loop, there is an inner loop that also runs n times. Inside the inner loop, the helper function is called which may run up to n times in the worst case (when the entire string is processed). Therefore, the time complexity is O(n * n * n) = O(n^3).

Space Complexity: The space complexity is determined by the maximum depth of recursion (which in this case is n, the length of the string) and the space needed for the variables in each function call. The space for the variables is constant, so the overall space complexity is O(n). This is because in the worst case, a recursive call could be made for each character in the string, and each recursive call is added to the call stack, hence the space complexity is proportional to the length of the string.
*/