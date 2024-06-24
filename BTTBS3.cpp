class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        
        vector<int> dp(n, 0);
        
        // First pass: calculate max profit with one transaction ending before or at each day
        int min_price = prices[0];
        for (int i = 1; i < n; i++) {
            dp[i] = max(dp[i-1], prices[i] - min_price);
            min_price = min(min_price, prices[i]);
        }
        
        // Second pass: calculate max profit with a second transaction starting after each day
        int max_profit = dp[n-1];
        int max_price = prices[n-1];
        for (int i = n-2; i >= 0; i--) {
            max_profit = max(max_profit, max_price - prices[i] + dp[i]);
            max_price = max(max_price, prices[i]);
        }
        
        return max_profit;
    }
};
