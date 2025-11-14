class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> diff(n+1,vector<int>(n+1,0));
        for(auto it: queries){
            int r1=it[0];
            int c1=it[1];
            int r2=it[2];
            int c2=it[3];
            diff[r1][c1]+=1;
            diff[r1][c2+1]-=1;
            diff[r2+1][c1]-=1;
            diff[r2+1][c2+1]+=1;

        }
        for(int i=0;i<n+1;i++){
            for(int j=1;j<n+1;j++){
                diff[i][j]+=diff[i][j-1];
            }
        }
       for(int j=0;j<n+1;j++){
            for(int i=1;i<n+1;i++){
                diff[i][j]+=diff[i-1][j];
            }
        }
        vector<vector<int>> ans(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans[i][j]=diff[i][j];
            }
        }
        return ans;
        
    }
};