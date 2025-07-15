class Solution {
public:
    vector<vector<int>> dp;
    int maxProfit(vector<int>& prices) {
        dp.resize(prices.size(),vector<int>(2,-1));
        return recurse(prices,0,1);
        
        
        
    }

    int recurse(vector<int>& prices,int index,int buy){
        if(index==prices.size()){
            return 0;
        }
        if(dp[index][buy]!=-1){
            return dp[index][buy];
        }
        int maximum=INT_MIN;
        if(buy){
            maximum=max(recurse(prices,index+1,0)-prices[index],recurse(prices,index+1,1));
        }
        else{
            maximum=max(recurse(prices,index+1,1)+prices[index],recurse(prices,index+1,0));
        }
        return dp[index][buy]=maximum;
    }
};