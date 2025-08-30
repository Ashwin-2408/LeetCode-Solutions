class Solution {
public:
    int ans=0;
    vector<vector<int>> dp;
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        dp.resize(n,vector<int>(m,-1));
        recurse(0,0,matrix);
        return ans*ans;
        
        
    }
    int recurse(int i,int j,vector<vector<char>>& matrix){
        int n=matrix.size();
        int m=matrix[0].size();
        
        if(i<0 || i==n || j<0 || j==m){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        
        int row=recurse(i,j+1,matrix);
        int col=recurse(i+1,j,matrix);
        int diagonal=recurse(i+1,j+1,matrix);
        if(matrix[i][j]=='0'){
            return dp[i][j]=0;
        }

        int val=1+min({row,col,diagonal});
        ans=max(ans,val);
        return dp[i][j]=val;
    }
};