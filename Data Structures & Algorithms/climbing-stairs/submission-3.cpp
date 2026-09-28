class Solution {
public:
    int climbStairs(int n) {
        if(n==1||n==2)
        return n;
         int p1=2,p2=1;
         for(int i=3;i<=n;i++){
            int temp=p1+p2;
            p2=p1;
            p1=temp;
            
         }
         return p1;
    }
};
