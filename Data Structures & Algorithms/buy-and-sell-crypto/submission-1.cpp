class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mp=0,buy=INT_MAX;
        for(int i=0;i<prices.size();i++){
           buy=min(buy,prices[i]);
           mp=max(mp,prices[i]-buy);
        }
        return mp;
    }
};
