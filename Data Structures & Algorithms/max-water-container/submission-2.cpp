class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left=0, right=heights.size()-1;
        int area=INT_MIN;
        // sort(heights.begin(),heights.end());
        while(left<right){
          int width=(right-left);
          int h = min(heights[left],heights[right]);
          area=max(area,width*h);
          if(heights[left]<=heights[right]){
            left++;
          }
          else{
            right--;
          }
        }
        return area;
    }
};
