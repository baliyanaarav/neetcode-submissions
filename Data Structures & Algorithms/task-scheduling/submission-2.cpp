class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>freq(26,0);
        for(int i=0;i<tasks.size();i++){
            freq[tasks[i]-'A']++;
        }
        priority_queue<int>pq;
        int ans=0;
        for(int i=0;i<freq.size();i++){
            if(freq[i]>0)
             pq.push(freq[i]);
        }
        while(!pq.empty()){
            vector<int>rm;
            for(int i=1;i<=n+1;i++){
                if(pq.empty()&&rm.empty())
                break;
                ans++;
                if(pq.empty())
                continue;
                int a =pq.top();
                pq.pop();
                a--;
                if(a>0)
                rm.push_back(a);
            }
            for(auto b:rm)
            pq.push(b);
        }
        return ans;

    }
};
