class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l=0,r=prices.size(), m=prices[0], profit=0;
        while(l<r){
            m=min(m,prices[l]);
            profit=max(prices[l] - m ,profit);
            l++;
        }
        return profit;
    }
};