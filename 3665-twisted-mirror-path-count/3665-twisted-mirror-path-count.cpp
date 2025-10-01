class Solution {
public:
    vector<vector<vector<long long>>> dp;
    int MOD=1e9+7;
    int uniquePaths(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        dp.assign(n,vector<vector<long long>>(m,vector<long long>(2,-1)));
        return (solve(grid,0,1,0)+solve(grid,1,0,1))%MOD;
        // 0 right 1 down
        
        
    }
    int solve(vector<vector<int>> & grid, int i , int j, int prev){
        if(grid.size()==i || grid[0].size()==j){
            return 0;
        }
        if(grid.size()-1==i && grid[0].size()-1==j){
            return 1;
        }
        if(dp[i][j][prev]!=-1){
            return dp[i][j][prev];
        }
        long long down=0;
        long long right=0;
        if(grid[i][j]==1){
            if(prev==0){
                down=solve(grid,i+1,j,1);

            }
            else{
                right=solve(grid,i,j+1,0);
            }
        }
        else{
            down=solve(grid,i+1,j,1);
            right=solve(grid,i,j+1,0);
        }
        return dp[i][j][prev]=(right+down)%(MOD);


    }
};