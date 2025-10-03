class Solution {
public:
    vector<vector<vector<int>>> dp;
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        dp.assign(n,vector<vector<int>>(2,vector<int>(2,-1)));
        return solve(prices,0,1,0);

        

        
    }
    int solve(vector<int> & prices, int index,int buy,int transactions){
        if(transactions==2 || index>=prices.size()){
            return 0;
        }
        if(dp[index][buy][transactions]!=-1){
            return dp[index][buy][transactions];
        }
        if(buy==1){
            return dp[index][buy][transactions]=max(solve(prices,index+1,0,transactions)-prices[index],solve(prices,index+1,1,transactions));
        }
        else{
            return dp[index][buy][transactions]=max(solve(prices,index+1,1,transactions+1)+prices[index],solve(prices,index+1,0,transactions));
        }
        
    }
};