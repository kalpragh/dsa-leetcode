class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int mintobuy=prices[0];
        for(int p:prices){
            mintobuy=min(p,mintobuy);
            profit=max(profit,p-mintobuy);
        }
        return profit;
    }
};