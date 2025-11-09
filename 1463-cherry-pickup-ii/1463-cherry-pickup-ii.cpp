class Solution {
public:
    vector<vector<vector<int>>> dp;
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        dp.resize(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return solve(grid,0,0,m-1);
        
    }
    int solve(vector<vector<int>>& grid,int i,int j1,int j2){
        if(j1<0 || j2<0 || j1>=grid[0].size() || j2>=grid[0].size() ){
            return INT_MIN;
        }
        if(i==grid.size()-1){
            if(j1==j2){
                return grid[i][j1];
            }
            else{
                return grid[i][j1] + grid[i][j2];
            }
        }
        if(dp[i][j1][j2]!=-1){
            return dp[i][j1][j2];
        }
        
        int max_gain=0;
        for(int k=-1;k<2;k++){
            max_gain=max(max_gain,solve(grid,i+1,j1+k,j2));
            max_gain=max(max_gain,solve(grid,i+1,j1+k,j2+1));
            max_gain=max(max_gain,solve(grid,i+1,j1+k,j2-1));
        }
        if(j1==j2){
            return dp[i][j1][j2]=grid[i][j1]+max_gain;
        }
        else{
            return dp[i][j1][j2]=grid[i][j1]+grid[i][j2]+max_gain;

        }
    }
};