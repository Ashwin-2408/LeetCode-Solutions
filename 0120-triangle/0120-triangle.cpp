class Solution {
public:
    
    unordered_map<int,unordered_map<int,int>> dp;
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        return recurse(triangle,0,0,n);
     
        
    }
    int recurse(vector<vector<int>> & triangle,int i,int j,int n){
        if(i==n){
           
            return 0;
        }
        if(dp[i].count(j)){
            return dp[i][j];
        }
        int sum=triangle[i][j];
        return dp[i][j]=sum+ min(recurse(triangle,i+1,j,n),recurse(triangle,i+1,j+1,n));
        

    }
};