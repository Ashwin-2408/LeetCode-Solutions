class Solution {
public:
    
    vector<vector<int>> dp;
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n=triangle.size();
        dp.resize(n,vector<int>(n,-1));
        return smallest_path(triangle,0,0);;
        
    }
    int smallest_path(vector<vector<int>>&triangle,int level,int i){
        
        if(level==triangle.size()){
            
            return 0;
        }
        if(i>=triangle[level].size()){
            return INT_MAX;
        }
        if(dp[level][i]!=-1){
            return dp[level][i];
        }
        return dp[level][i]= triangle[level][i]+ min(smallest_path(triangle,level+1,i),smallest_path(triangle,level+1,i+1));
        
        
    }
};