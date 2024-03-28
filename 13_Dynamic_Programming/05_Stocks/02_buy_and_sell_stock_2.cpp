class Solution {
private:
    int memoisation(vector<int> &prices, int ind, int canBuy, vector<vector<int>> &dp){
        //even if you bought something you cannot sell it if stocks are exhausted
        if(ind == prices.size()){
            return 0;
        }
        if(dp[ind][canBuy] != -1) return dp[ind][canBuy];
        long long profit = 0;
        if(canBuy){
            //negating as the stock is bought and change canBuy counter to 0
            int buy = -prices[ind] + memoisation(prices, ind+1, 0, dp);
            int notBuy = 0 + memoisation(prices, ind+1, 1, dp);
            profit = max(buy, notBuy);
        }
        //if bought sell
        else{
            //after sell you can buy again so change counter of buy to 1
            int sell = prices[ind] + memoisation(prices, ind+1, 1, dp);
            int notSell = 0 + memoisation(prices, ind+1, 0, dp);
            profit = max(sell, notSell);
        }
        return dp[ind][canBuy] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 1) return 0;
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        //initially you can buy the stock
        return memoisation(prices, 0, 1, dp);
    }
};

//Tabulation
class Solution{
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 1) return 0;
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        //base cases
        dp[n][0] = 0;
        dp[n][1] = 0;
        for(int i=n-1; i>=0; i--){
            for(int j=0; j<2; j++){
                long long profit = 0;
                if(j == 1){
                    int buy = -prices[i] + dp[i+1][0];
                    int notBuy = 0 + dp[i+1][1];
                    profit = max(buy, notBuy);
                }
                else{
                    int sell = prices[i] + dp[i+1][1];
                    int notSell = 0 + dp[i+1][0];
                    profit = max(sell, notSell);
                }
                dp[i][j] = profit;
            }
        }
        //initially you can buy the stock 
        return dp[0][1];
    }
};

//Space optimisation
class Solution {
// private:
//     int memoisation(vector<int> &prices, int ind, int canBuy, vector<vector<int>> &dp){
//         //even if you bought something you cannot sell it if stocks are exhausted
//         if(ind == prices.size()){
//             return 0;
//         }
//         if(dp[ind][canBuy] != -1) return dp[ind][canBuy];
//         long long profit = 0;
//         if(canBuy){
//             //negating as the stock is bought and change canBuy counter to 0
//             int buy = -prices[ind] + memoisation(prices, ind+1, 0, dp);
//             int notBuy = 0 + memoisation(prices, ind+1, 1, dp);
//             profit = max(buy, notBuy);
//         }
//         //if bought sell
//         else{
//             //after sell you can buy again so change counter of buy to 1
//             int sell = prices[ind] + memoisation(prices, ind+1, 1, dp);
//             int notSell = 0 + memoisation(prices, ind+1, 0, dp);
//             profit = max(sell, notSell);
//         }
//         return dp[ind][canBuy] = profit;
//     }
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 1) return 0;
        int n = prices.size();
        vector<int> front(2, 0), curr(2, 0);
        for(int i=n-1; i>=0; i--){
            for(int j=0; j<2; j++){
                long long profit = 0;
                if(j == 1){
                    int buy = -prices[i] + front[0];
                    int notBuy = 0 + front[1];
                    profit = max(buy, notBuy);
                }
                else{
                    int sell = prices[i] + front[1];
                    int notSell = 0 + front[0];
                    profit = max(sell, notSell);
                }
                curr[j] = profit;
            }
            front = curr;
        }
        //initially you can buy the stock 
        return front[1];
    }
};