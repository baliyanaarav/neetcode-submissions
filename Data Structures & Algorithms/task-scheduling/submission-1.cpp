class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int>pq;
        vector<int>freq(26,0);
        int ans=0;
        for(char ch:tasks){
            freq[ch-'A']++;
        }
        for(int f:freq){
            if(f>0)
            pq.push(f);
        }
        while(!pq.empty()){
            vector<int>temp;
            for(int i=0;i<=n;i++){
                if(pq.empty()&&temp.empty())
                break;
                                ans++;
                if(pq.empty())
                continue;
                int t=pq.top();
                pq.pop();
                t--;
                
                if(t>0)
                temp.push_back(t);
            }
            for(int i:temp)
            pq.push(i);
        }
        return ans;
    }
};
