class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if(n<=2){
            return min(cost[0],cost[1]);
        }
        int pre1=0;
        int pre2=0;
        for(int i=2;i<=n;i++){
           int temp=min(pre1+cost[i-1],pre2+cost[i-2]);
           pre2=pre1;
            pre1=temp;
        }
        return pre1;
    }
};
