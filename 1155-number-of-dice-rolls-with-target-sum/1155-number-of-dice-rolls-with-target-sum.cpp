class Solution {
public:
    vector<vector<int>> dp;
    int MOD=1e9+7;
    int numRollsToTarget(int n, int k, int target) {
        dp.assign(n+1,vector<int>(target+1,-1));
        return solve(n,k,target);
        
    }
    int solve(int n,int k ,int target){
        if(target==0 && n==0){
            return 1;
        }
        if(n==0 || target<0){
            return 0;
        }
        if(dp[n][target]!=-1){
            return dp[n][target];
        }
        int ans=0;
        for(int i=1;i<=k;i++){
            ans+=solve(n-1,k,target-i);
            ans%=(MOD);
        }
        return dp[n][target]=ans;
    }
};