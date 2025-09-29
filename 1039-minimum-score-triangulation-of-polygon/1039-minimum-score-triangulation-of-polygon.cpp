class Solution {
public:
    vector<vector<int>> dp;
    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        dp.resize(n,vector<int>(n,-1));
        return solve(values,0,n-1);
        
       
    }

    int solve(vector<int>& values,int i, int j){
        if(j-i+1<3){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int value=INT_MAX;
        for(int k=i+1;k<j;k++){
            value=min(value,solve(values,i,k)+solve(values,k,j)+(values[i]*values[j]*values[k]));
            
        }
        return dp[i][j]=value;

    }
};