class Solution {
public:
    int trap(vector<int>& height) {
        int trapped=0;
        int left =0;
        int right=height.size()-1;
        int leftmax=INT_MIN,rightmax=INT_MIN;
        while(left<=right){
          leftmax=max(height[left],leftmax);
          rightmax=max(height[right],rightmax);
          if(leftmax<rightmax){
             trapped+=(leftmax-height[left]);
             left++;
          }
          else{
             trapped+=(rightmax-height[right]);
             right--;
          }
          
        }return trapped;
    }
};
