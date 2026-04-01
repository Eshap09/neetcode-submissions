class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mx = 0;
        int mn = prices[0];
        for(int i=1;i<prices.size();i++){
            mx = max(prices[i]-mn,mx);
            mn = min(prices[i],mn);
        }
        return mx;
    }
};
