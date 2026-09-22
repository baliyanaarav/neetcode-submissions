class Solution {
public:
    vector<int> nsfinder(vector<int>&heights, int n){
        stack<int>st;
        vector<int>ans(n,n);
        for(int i=0;i<n;i++){
            while(!st.empty()&&heights[i]<heights[st.top()]){
                ans[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
     vector<int> psfinder(vector<int>&heights, int n){
        stack<int>st;
        vector<int>ans(n,-1);
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&heights[i]<heights[st.top()]){
                ans[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>ns = nsfinder(heights,n);
        vector<int>ps=psfinder(heights,n);
        int area = INT_MIN;
        for(int i =0;i<n;i++){
            area = max(area, (ns[i]-ps[i]-1)*heights[i]);
        }
        return area;
    }
};
