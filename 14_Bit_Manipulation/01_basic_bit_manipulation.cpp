//checking ith bit is set or not
//setting ith bit
//clearing ith bit
vector<int> bitManipulation(int num, int i){
   vector<int> ans;
   int ithBit = (num >> i)%2;
   //right shift 1 to ith position and perform OR operation
   int setBit = (1<<i) | num;
   //right shift 1 to ith position (take neagation) and perform AND operation
   int clearBit = ~(1<<i) & num;
   ans.push_back(ithBit);
   ans.push_back(setBit);
   ans.push_back(clearBit);
   return ans;
}

//Finding whether given number is power of 2 or not
//Approach
// Now consider :-
// bit representation of 7  -> 0111
// bit representation of 8  -> 1000
// bitwise AND of 7 and 8 -> 0000
// we are gonna use this property for for all numbers which are powers of two

class Solution {
public:
   bool isPowerOfTwo(int n) {
      if(n<=0) return false;
      return (n&n-1) == 0;
   }
};

//swaping two numbers without extra variable

void swap(int &a, int &b){
   a = a^b; 
   b = a^b; //(a^b)^b = a
   a = a^b; //a^(a^b) = b
}

//toggling ith bit

void toggle(int n, int i){
   //xor at that bit position 
   return n^(1<<i);
}

//removing last set bit
//example 40 - 101000, 39 - 100111 => and operation gives 100000
void remove(int n, int i){
   return n&n-1;
}

//converting one number to another
class Solution {
public:
   int minBitFlips(int start, int goal) {
      int xorOPeration;
      xorOPeration = start^goal; //gives 1 when bits are different.
      int ans = 0;
      for(int i=0; i<31; i++){
         if(xorOPeration & (1<<i)){
            ans++;
         }
      }
      return ans;
   }
};
