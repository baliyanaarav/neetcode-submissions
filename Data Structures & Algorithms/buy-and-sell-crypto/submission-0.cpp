class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mp=INT_MIN;
        int buy=prices[0];
        for(int i=1;i<prices.size();i++){
            if(prices[i]<buy)
            buy=prices[i];
            else 
            mp=max(mp,prices[i]-buy);
        }
        if(mp==INT_MIN)
        return 0;
        return mp;
    }
};
