class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
     int n = position.size();
     vector<pair<int,float>>cars;
     for(int i=0;i<n;i++){
        float time = (1.0*(target-position[i])/speed[i]);
        cars.push_back({position[i],time});
     }  
     sort(cars.begin(),cars.end()); 
     int fleets=0;
     stack<float>st;
     for(int i=n-1;i>=0;i--){
       if(!st.empty()&&st.top()>=cars[i].second){
        continue;
       }
       else{
        fleets++;
        st.push(cars[i].second);
       }
     }
     return fleets;
    }
};
