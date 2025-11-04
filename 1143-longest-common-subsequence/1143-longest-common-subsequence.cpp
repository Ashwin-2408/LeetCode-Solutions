class Solution {
public:
    vector<vector<int>> dp;
    int longestCommonSubsequence(string text1, string text2) {
        dp.resize(text1.size(),vector<int>(text2.size(),-1));
        return solve(text1,text2,text1.size()-1,text2.size()-1);
        
    }
    int solve(string text1,string text2,int i,int j){
        if(i<0 || j<0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(text1[i]==text2[j]){
            return dp[i][j]=1+solve(text1,text2,i-1,j-1);
        }
        return dp[i][j]=max(solve(text1,text2,i-1,j),solve(text1,text2,i,j-1));
    }
};