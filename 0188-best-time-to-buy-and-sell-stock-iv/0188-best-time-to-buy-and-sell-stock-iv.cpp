class Solution {
public:
    vector<vector<vector<int>>> dp;
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        dp.assign(n,vector<vector<int>>(2,vector<int>(k,-1)));
        return solve(prices,0,1,0,k);
        
    }
    int solve(vector<int>& prices,int index,int buy,int transactions,int k){
        if(k==transactions || index>=prices.size()){
            return 0;
        }
        if(dp[index][buy][transactions]!=-1){
            return dp[index][buy][transactions];
        }
        if(buy==1){
            return dp[index][buy][transactions]=max(solve(prices,index+1,0,transactions,k)-prices[index],solve(prices,index+1,1,transactions,k));
        }
        else{
            return dp[index][buy][transactions]=max(solve(prices,index+1,1,transactions+1,k)+prices[index],solve(prices,index+1,0,transactions,k));
        }
    }
};