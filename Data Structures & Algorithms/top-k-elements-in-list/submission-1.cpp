class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        unordered_map<int,int>um;
        for(int i:nums){
            um[i]++;
        }
        int n=nums.size();
        vector<vector<int>>freq(n+1);
        for(auto it:um){
            freq[it.second].push_back(it.first);
        }
        int i=n;
        while(i>=0&&k>0){
            for(auto it:freq[i]){
                ans.push_back(it);
                k--;
            }
            i--;

        }
        return ans;

    }
};
