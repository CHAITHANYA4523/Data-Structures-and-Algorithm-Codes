class Solution
{
    public:
    //Function to calculate the span of stocks price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       stack<int> st;
       vector<int> ans(n, 1); // initialises all indices by 1
       for(int i=0; i<n; i++){
           while(!st.empty() && price[st.top()] <= price[i]){ //pop if less valued stock is available
               st.pop();
           }
           if(st.empty()) ans[i] = i+1; //stack is empty so, return index + 1
           else ans[i] = i-st.top(); 
           st.push(i);
       }
       return ans;
    }
};

//leetcode
class StockSpanner {
public:
    StockSpanner() {
        
    }
    stack<pair<int, int>> st;  // Using a pair to store the price and span 
    int next(int price) {
        int span = 1;    
        while (!st.empty() && price >= st.top().first) {
            span += st.top().second;
            st.pop();
        }   
        st.push({price, span});    
        return span;
    }
};