class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>um;
        for(int i=0;i<nums.size();i++){
        um[nums[i]]++;
        }
        vector<vector<int>>bucket(nums.size()+1);
        for(auto i:um){
            bucket[i.second].push_back(i.first);
        }
        vector<int>ans;
        for(int i=nums.size();i>=0&&ans.size()<k;i--){
      for(int j=0;j<bucket[i].size();j++){
        ans.push_back(bucket[i][j]);
      }
        }
        return ans;

    }
};
