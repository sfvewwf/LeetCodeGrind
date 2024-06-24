class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n < 2)
            return 0;
        int maxer = 0;
        int gday = prices[0];
        for(int i = 1;i < n; i++){
            maxer = max(maxer, prices[i]-gday);
            gday = min(gday, prices[i]);
        }
        return maxer;
    }
};
