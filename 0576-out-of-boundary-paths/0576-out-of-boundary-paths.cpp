class Solution {
public:
    vector<vector<vector<int>>> dp;
    int MOD=1e9+7;
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        dp.resize(m,vector<vector<int>>(n,vector<int>(maxMove+1,-1)));
        return solve(m,n,maxMove,startRow,startColumn);


        
    }
    int solve(int m,int n,int maxMove,int i, int j){
        if(i>=m || j>=n || i<0 || j<0){
            return 1;
        }
        if(maxMove==0){
            return 0;
        }
        if(dp[i][j][maxMove]!=-1){
            return dp[i][j][maxMove];
        }
        int ans=0;
        ans+=solve(m,n,maxMove-1,i+1,j)%MOD;
        ans+=solve(m,n,maxMove-1,i-1,j)%MOD;
        ans+=solve(m,n,maxMove-1,i,j+1)%MOD;
        ans+=solve(m,n,maxMove-1,i,j-1)%MOD;
        return dp[i][j][maxMove]=ans;
    }
};