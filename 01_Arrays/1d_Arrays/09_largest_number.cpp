
//gives TLE for larger numbers
/*
Approach: first sort the numbers based on the condition that which number coming first in the nums array would yield the bigger number after concatenating, then add the numbers to ans by traversing
*/
class Solution {
private:
    static int len(int n) {
        if (n == 0) return 1; // Special case for handling 0
        int count = 0;
        while (n) {
            n = n / 10;
            count++;
        }
        return count;
    }
    static bool compareNumber(int num1, int num2) {
        int num1Len = len(num1);
        int num2Len = len(num2);
        long long int num1WithPow = num1 * pow(10, num2Len);
        long long int num2WithPow = num2 * pow(10, num1Len);
        //follow the order whose combination gives larger number
        return num1WithPow + num2 > num2WithPow + num1;
    }
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), compareNumber);
        string ans = "";
        for(int i=0; i<nums.size(); i++) ans += to_string(nums[i]);
        int flag = 0;
        //if ans is like "0000" return "0"
        for(auto it:ans){
            if(it != '0'){
                flag = 1;
            }
        }
        if(flag == 0) return "0";
        return ans;
    }
};

class Solution {
private:
    static bool compareNumber(int num1, int num2) {
        string str1 = to_string(num1);
        string str2 = to_string(num2);
        //follow the order whose combination gives larger number
        return str1 + str2 > str2 + str1;
    }
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), compareNumber);
        string ans = "";
        for(int i=0; i<nums.size(); i++) ans += to_string(nums[i]);
        int flag = 0;
        //if ans is like "0000" return "0"
        for(auto it:ans){
            if(it != '0'){
                flag = 1;
            }
        }
        if(flag == 0) return "0";
        return ans;
    }
};