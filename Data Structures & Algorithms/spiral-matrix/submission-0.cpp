class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size(), n = matrix[0].size();
        int sr=0, er=m-1, sc=0, ec=n-1;
        vector<int>ans;
        while(sr<=er&&sc<=ec){
        for(int j=sc;j<=ec;j++){
            ans.push_back(matrix[sr][j]);
        }
        sr++;
        for(int j=sr;j<=er;j++){
            ans.push_back(matrix[j][ec]);
        }
        ec--;
        if(sr<=er){
        for(int j=ec;j>=sc;j--){
            ans.push_back(matrix[er][j]);
        }
        er--;}
        if(sc<=ec){
        for(int j=er;j>=sr;j--){
            ans.push_back(matrix[j][sc]);
        }
        sc++;}
        }
        return ans;
    }
};
