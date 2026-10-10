class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tg=0,cg=0,start=0;
        for(int i=0;i<gas.size();i++){
            int diff=gas[i]-cost[i];
             tg=diff+tg;
            cg+=diff;
            if(cg<0){
                start=i+1;
                cg=0;
            }
        }
         return tg >= 0 ? start : -1;
    }
};
