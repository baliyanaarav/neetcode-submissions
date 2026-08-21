class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ans=0,curr=0;
        int i =0,j=heights.size()-1;
        while(i<j){
         int width=(j-i);
         curr=width*(min(heights[i],heights[j]));
         ans=max(ans,curr);
         if(heights[i]<=heights[j])
         i++;
         else
         j--;
        }
        return ans;
    }
};
