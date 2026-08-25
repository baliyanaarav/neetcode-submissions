class Solution {
public:
    int findMin(vector<int> &arr) {
        int n = arr.size();
        int l=0, r=n-1;
        int ans=INT_MAX;
        while(l<=r){
            if(arr[l]<=arr[r]){
                ans= min(ans,arr[l]);
                break;
            }
            int mid = l+(r-l)/2;
           if(arr[l]<=arr[mid]){
            ans=min(ans,arr[l]);
            l=mid+1;
           }
           else{
            ans = min(ans,arr[mid]);
            r=mid-1;
           }
        }
        return ans;
    }
};
