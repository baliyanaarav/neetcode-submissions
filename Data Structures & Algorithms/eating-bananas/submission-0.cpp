class Solution {
public:
bool caneat(vector<int>piles,int k,int h){
    int ak=0;
for(int i=0;i<piles.size();i++){
ak+=ceil((double)piles[i]/k);
}
if(ak<=h)
return true;
return false;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int r=*max_element(piles.begin(),piles.end());
        while(l<r){
         int mid=l+(r-l)/2;
         if(caneat(piles,mid,h)){
            r=mid;
         }
         else{
            l=mid+1;
         }
        }
        return l;
    }
};
