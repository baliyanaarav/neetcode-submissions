class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ans=0;
        int left=0, right=heights.size()-1;
        while(left<right){
          int height= min(heights[left],heights[right]);
          int breadth= right-left;
          ans=max(ans, height*breadth);
          if(heights[left]<heights[right])
          left++;
          else
          right--;
        }
        return ans;
    }
};
