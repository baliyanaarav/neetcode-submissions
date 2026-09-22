class Solution {
public:
    bool caneat(vector<int>&piles, int h, int k){
        int taken =0;
        for(int i=0;i<piles.size();i++){
            taken+=ceil(piles[i]*1.0/k);
        }
        return taken<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h){
        int l=1;
        int r= *max_element(piles.begin(),piles.end());
       int ans=INT_MAX;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(caneat(piles,h,mid)){
               ans=min(ans,mid);
               r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};
