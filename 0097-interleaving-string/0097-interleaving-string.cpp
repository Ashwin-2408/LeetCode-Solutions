class Solution {
public:
    vector<vector<int>> dp;
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()<s3.size()){
            return false;
        }
        dp.resize(s1.size()+1,vector<int>(s2.size()+1,-1));
        return solve(s1,s2,s3,0,0,0);
        
    }
    bool solve(string &s1,string&s2,string &s3,int i,int j,int k){
        if(k==s3.size() && i==s1.size() && j==s2.size()){  
            return true;
        }
        bool ans=false;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
       

        if(i<s1.size()){
            if(s1[i]==s3[k]){
                ans = ans || solve(s1,s2,s3,i+1,j,k+1);
            }
            
        }
        if(j<s2.size()){
            if(s2[j]==s3[k]){
                ans = ans || solve(s1,s2,s3,i,j+1,k+1);

            }

        }

        
        return dp[i][j]=ans;

    }
};