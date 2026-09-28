class Solution {
public:
    int getsq(int n){
        int sum=0;
        while(n){
            int d=n%10;
            n=n/10;
            sum+=(d*d);
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int>s;
        while(n!=1){
            if(s.count(n))
            return false;
            s.insert(n);
            n=getsq(n);
            if(n==1)
            break;
        }
        return true;
    }
};
