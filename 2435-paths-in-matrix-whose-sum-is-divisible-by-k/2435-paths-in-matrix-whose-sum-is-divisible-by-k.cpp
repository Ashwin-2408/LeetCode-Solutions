class Solution {
public:
    int MOD=1e9+7;
    vector<vector<vector<int>>> dp;
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        dp.resize(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(k,-1)));
        return solve(grid,0,0,k,0);
        
        
    }
    int solve(vector<vector<int>> & grid, int i ,int j , int k,int curr_sum){
        int n=grid.size();
        int m=grid[0].size();
        if(i==n || j==m){
            return 0;
        }
        if(i==n-1 && j==m-1){
            if((curr_sum+grid[i][j])%k==0){
                return 1;
            }
            else{
                return 0;
            }
        }
        curr_sum=(curr_sum+grid[i][j])%k;
        if(dp[i][j][curr_sum]!=-1){
            return dp[i][j][curr_sum];
        }
        int ans= (solve(grid,i+1,j,k,curr_sum)%MOD+solve(grid,i,j+1,k,curr_sum)%MOD)%MOD;
        return dp[i][j][curr_sum]=ans;


    }
};