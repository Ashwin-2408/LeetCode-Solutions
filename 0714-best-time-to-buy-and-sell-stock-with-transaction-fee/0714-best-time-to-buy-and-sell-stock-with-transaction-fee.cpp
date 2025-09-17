class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,0));
        dp[0][0]=0;
        dp[0][1]=-prices[0];
        for(int i=1;i<n;i++){
            for(int j=0;j<2;j++){
                if(j==0){
                    dp[i][j]=max(dp[i-1][0],prices[i]+dp[i-1][1]-fee);
                }
                else{
                    dp[i][j]=max(dp[i-1][1],dp[i-1][0]-prices[i]);
                }
            }
        }
        return dp[n-1][0];

    }
};