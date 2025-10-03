class Solution {
public:
    vector<vector<int>> dp;
    int maxProfit(vector<int>& prices) {
        dp.assign(prices.size(),vector<int>(2,-1));
        return solve(prices,0,1);
        
    }
    int solve(vector<int>& prices,int i,int buy){
        if(i>=prices.size()){
            return 0;
        }
        if(dp[i][buy]!=-1){
            return dp[i][buy];
        }
        int value=prices[i];
        if(buy==1){
            return  max(solve(prices,i+1,0)-value,solve(prices,i+1,1));

        }
        else if(buy==0){
            return max(solve(prices,i+2,1)+value,solve(prices,i+1,0));
        }
        return 0;


    }
};