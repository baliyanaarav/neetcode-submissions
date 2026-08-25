class Solution {
public:
    vector<int> pse(vector<int> heights,int st, int en){
    stack<int>stac;
    vector<int>ans(en-st+1,-1);
    for(int i =en;i>=st;i--){
      if(stac.empty()){
        stac.push(i);
      }
      else{
        while(!stac.empty()&&heights[stac.top()]>heights[i]){
          ans[stac.top()]=i;
          stac.pop();
        }
        stac.push(i);
      }
    }
    return ans;
   }
   vector<int> nse(vector<int> heights,int st, int en){
    stack<int>stac;
    vector<int>ans(en-st+1,-1);
    for(int i =st;i<=en;i++){
      if(stac.empty()){
        stac.push(i);
      }
      else{
        while(!stac.empty()&&heights[stac.top()]>heights[i]){
          ans[stac.top()]=i;
          stac.pop();
        }
        stac.push(i);
      }
    }
    return ans;
   }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>ps= pse(heights,0,n-1);
        vector<int>ns=nse(heights,0,n-1);
        int area = INT_MIN;
        for(int i =0;i<n;i++){
            int l = heights[i];
            if(ns[i]==-1){
                ns[i]=n;
            }
            int b = ns[i]-ps[i]-1;
             area=max(area,l*b);
        }
        return area;
    }
};
