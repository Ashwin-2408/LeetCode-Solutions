class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> dp(n+1,0);
        int MOD=1e9+7;
        dp[0]=0;
        dp[1]=1;
        long long count=0;
        for(int i=2;i<n+1;i++){
            if(i-delay>=1){
                count=(count+dp[i-delay])%MOD;
            }
            if(i-forget>=1){
                count=(count-dp[i-forget]+MOD)%MOD;
            }
            dp[i]=count;
           

        }
        
   
    int ans=0;
    for(int i=n-forget+1;i<=n;i++){
        ans=(ans+dp[i])%MOD;
    }
    return ans;
        
    }
};