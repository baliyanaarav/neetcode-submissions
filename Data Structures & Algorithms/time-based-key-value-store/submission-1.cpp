class TimeMap {
public:
     unordered_map<string,vector<pair<string,int>>>um;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        if(um.find(key)==um.end()){
            um[key]={};
            um[key].push_back({value,timestamp});
            return;
        }
um[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        if(um.find(key)==um.end())
        return "";
        string ans;
        vector<pair<string,int>>&arr=um[key];
        int l=0,r=arr.size()-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(arr[mid].second==timestamp)
            return arr[mid].first;
            else if(arr[mid].second>timestamp){
                r=mid-1;
            }
            else{
                ans=arr[mid].first;
                l=mid+1;
            }
        }
        return ans;
    }
};
