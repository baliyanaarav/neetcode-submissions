class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n =cost.size();
        if(n==2)
        return min(cost[0],cost[1]);
        int p1=0;
        int p2=0;
        for(int i=2;i<=n;i++){
            int temp=min(p1+cost[i-1],p2+cost[i-2]);
            p2=p1;
            p1=temp;
        }
        return p1;
    }
};
