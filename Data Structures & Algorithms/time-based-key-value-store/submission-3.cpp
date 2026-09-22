class TimeMap {
public:
    unordered_map<string,vector<pair<string,int>>>um;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        um[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        if(um.find(key)==um.end())
        return "";
        vector<pair<string,int>>&p1=um[key];
        int l=0, r=p1.size()-1;
        string ans="";
        while(l<=r){
            int mid = l+(r-l)/2;
            if(p1[mid].second==timestamp)
            return p1[mid].first;
            else if(p1[mid].second>timestamp){
             r=mid-1;
            }
            else{
                ans=p1[mid].first;
                l=mid+1;
            }
        }
        return ans;
    }
};
