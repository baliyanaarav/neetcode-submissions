class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans(n+1,0);
        for(int i=0;i<=n;i++){
            int t=0;
            int j=i;
            while(j){
                t+=(j&1);
                j=j>>1;
            }
            ans[i]=t;
        }
        return ans;

    }
};
