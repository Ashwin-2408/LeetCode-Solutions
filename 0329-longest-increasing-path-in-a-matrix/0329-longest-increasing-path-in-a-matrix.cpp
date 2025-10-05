class Solution {
public:
    vector<vector<int>> dp;
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int ans=0;
        dp.assign(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=max(ans,longest_path(matrix,i,j,-1));
                
            }
        }
        return ans;

        
    }
    int longest_path(vector<vector<int>> & matrix, int i ,int j,int prev){
        if(i<0 || i>=matrix.size() || j<0 || j>=matrix[0].size() || matrix[i][j]<=prev){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        return dp[i][j]=1+max({longest_path(matrix,i+1,j,matrix[i][j]),longest_path(matrix,i,j+1,matrix[i][j]),longest_path(matrix,i,j-1,matrix[i][j]),longest_path(matrix,i-1,j,matrix[i][j])});


    }
};