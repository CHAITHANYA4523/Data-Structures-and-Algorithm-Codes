//max profit with atmost two transactions

//we take 3d dp as the profit is dependent on three states (index, canBuy, transactions) 

//memoisation
class Solution {
private:
    int memoisation(vector<int>& prices, int ind, int canBuy,
    vector<vector<vector<int>>> &dp, int transactions){
        if(ind == prices.size()){
            return 0;
        }
        if(transactions == 0){
            return 0; 
        }
        if(dp[ind][canBuy][transactions] != -1) return dp[ind][canBuy][transactions];
        long long profit = 0;
        if(canBuy){
            int buy = -prices[ind] + memoisation(prices, ind+1, 0, dp, transactions);
            int notBuy = memoisation(prices, ind+1, 1, dp, transactions);
            profit = max(buy, notBuy);
        }
        else{
            int sell = prices[ind] + memoisation(prices, ind+1, 1, dp, transactions-1);
            int notSell = memoisation(prices, ind+1, 0, dp, transactions);
            profit = max(sell, notSell);
        }
        return dp[ind][canBuy][transactions] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return memoisation(prices, 0, 1, dp, 2);
    }
};

//tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
        //base cases
        // for(int i=0; i<2; i++){
        //     for(int j=0; j<3; j++){
        //         dp[n][i][j] = 0;
        //     }
        // }
        // for(int i=0; i<=n; i++){
        //     for(int j=0; j<2; j++){
        //         dp[i][j][0] = 0;
        //     }
        // }
        for(int i=n-1; i>=0; i--){
            for(int j=0; j<=1; j++){
                for(int k=1; k<=2; k++){
                    if(j==1){
                        int buy = -prices[i] + dp[i+1][0][k];
                        int notBuy = dp[i+1][1][k];
                        dp[i][j][k] = max(buy, notBuy);
                    }
                    else{
                        int sell = prices[i] + dp[i+1][1][k-1];
                        int notSell = dp[i+1][0][k];
                        dp[i][j][k] = max(sell, notSell);
                    }
                }
            }
        }
        return dp[0][1][2];
    }
};

//space optimisation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> front(2, vector<int>(3, 0));
        vector<vector<int>> curr(2, vector<int>(3, 0));
        for(int i=n-1; i>=0; i--){
            for(int j=0; j<=1; j++){
                for(int k=1; k<=2; k++){
                    if(j==1){
                        int buy = -prices[i] + front[0][k];
                        int notBuy = front[1][k];
                        curr[j][k] = max(buy, notBuy);
                    }
                    else{
                        int sell = prices[i] + front[1][k-1];
                        int notSell = front[0][k];
                        curr[j][k] = max(sell, notSell);
                    }
                }
            }
            front = curr;
        }
        return front[1][2];
    }
};

