class Solution {
public:
    vector<vector<vector<int>>> dp;
    int MOD=1e9+7;
    int checkRecord(int n) {
        dp.resize(n+1,vector<vector<int>>(3,vector<int>(4,-1)));
        return solve(n,0,0);
        
    }
    int solve(int n,int absent,int late){
        
        if(absent>=2 || late>=3){
            return 0;
        }
        if(dp[n][absent][late]!=-1){
            return dp[n][absent][late];
        }
        if(n==0){
            return 1;
        }
        return dp[n][absent][late]=((solve(n-1,absent+1,0)%MOD+solve(n-1,absent,late+1)%MOD)%MOD+solve(n-1,absent,0)%MOD)%MOD;
        

    }
};