class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int> maxProfitPQ; // Max-heap for profits
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minCapitalPQ; // Min-heap for capital

        // Initialize minCapitalPQ with all projects
        for (int i = 0; i < capital.size(); ++i) {
            minCapitalPQ.push({capital[i], profits[i]});
        }

        // Loop for k times or until we run out of projects
        for (int i = 0; i < k; ++i) {
            // Transfer all projects that can be started with current capital to maxProfitPQ
            while (!minCapitalPQ.empty() && minCapitalPQ.top().first <= w) {
                maxProfitPQ.push(minCapitalPQ.top().second);
                minCapitalPQ.pop();
            }

            // If no projects can be started, break the loop
            if (maxProfitPQ.empty()) break;

            // Select the project with maximum profit
            w += maxProfitPQ.top();
            maxProfitPQ.pop();
        }
        return w;
    }
};
