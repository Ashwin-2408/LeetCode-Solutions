class Solution {
public:
    vector<vector<vector<int>>> dp;
    int findMaxForm(vector<string>& strs, int m, int n) {
        int x=strs.size();
        dp.assign(x+1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));

        vector<pair<int,int>> arr;
        for(auto it: strs){
            int zero=0;
            int one=0;
            for(int i=0;i<it.size();i++){
                if(it[i]=='1'){
                    one++;
                }
                else{
                    zero++;
                }
            }
            arr.push_back({zero,one});
        }
        return solve(arr,0,m,n);
        
    }
    int solve(vector<pair<int,int>>& arr,int i, int m, int n){
        if(i==arr.size()){
            return 0;
        }
        if(dp[i][m][n]!=-1){
            return dp[i][m][n];
        }
        if(arr[i].first<= m && arr[i].second<=n){
            return dp[i][m][n]=max(1+solve(arr,i+1,m-arr[i].first,n-arr[i].second),solve(arr,i+1,m,n));
        }
        else{
            return dp[i][m][n]=solve(arr,i+1,m,n);
        }

    }
};