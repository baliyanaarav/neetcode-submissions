class Solution {
public:
    int climbStairs(int n) {
        if(n==1||n==2)
        return n;
        int pre2=1;
        int pre1=2;
        for(int i=3;i<=n;i++){
           int temp=pre2;
           pre2=pre1;
           pre1=temp+pre1;
        }
        return pre1;
    }
};
