class Solution {
public:
    int trap(vector<int>& heights) {
        int l=0, r=heights.size()-1;
        int ans=0;
        int leftmax=INT_MIN,rightmax=INT_MIN;
        while(l<=r){
          leftmax=max(heights[l],leftmax);
          rightmax=max(heights[r],rightmax);
          if(leftmax<=rightmax){
            ans+=(leftmax-heights[l]);
            l++;
          }
          else{
            ans+=(rightmax-heights[r]);
            r--;
          }
        }
        return ans;
    }
};
