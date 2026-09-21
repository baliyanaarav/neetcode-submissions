class Solution {
public:

    string encode(vector<string>& strs) {
           string encoded="";
           for(auto str: strs){
            encoded+=(to_string(str.size())+"#"+str);
           }
           return encoded;
    }

    vector<string> decode(string s) {
        vector<string>decoded;
        int i=0;
        while(i<s.size()){
            int j=i;
            string curr="";
            while(s[j]!='#'){
                j++;
            }
            int length=stoi(s.substr(i,j-i));
            for(int k=j+1;k<=j+length;k++){
                curr+=s[k];
            }
             i=j+length+1;
            decoded.push_back(curr);
        }
        return decoded;
    }
};
