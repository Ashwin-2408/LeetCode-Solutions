class Solution {
public:
    vector<vector<int>> dp;
    int coinChange(vector<int>& coins, int amount) {
        dp.resize(coins.size(),vector<int>(amount+1,-1));
        int coin=recurse(coins,amount,0);
        if(coin==INT_MAX-1){
            return -1;
        }
        return coin;
        
    }
    int recurse(vector<int>&coins,int amount,int index){
        if(amount==0){
            return 0;
        }
        if(index>=coins.size()){
            return INT_MAX-1;
            
        }
        if(dp[index][amount]!=-1){
            return dp[index][amount];
        }
        if(coins[index]<=amount){
            return dp[index][amount]=min(1+recurse(coins,amount-coins[index],index),recurse(coins,amount,index+1));
        }
        return dp[index][amount]=recurse(coins,amount,index+1);
    }
};