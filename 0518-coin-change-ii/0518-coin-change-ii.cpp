class Solution {
public:
    vector<vector<int>> dp;
    int change(int amount, vector<int>& coins) {
        dp.resize(coins.size(),vector<int> (amount+1,-1));
        return recurse(coins,amount,0);
        
    }
    int recurse(vector<int>& coins,int amount,int index){
        if(amount==0){
            return 1;
        }
        if(index>=coins.size()){
            return 0;
        }
        if(dp[index][amount]!=-1){
            return dp[index][amount];
        }
        if(coins[index]<=amount){
            return dp[index][amount]=recurse(coins,amount-coins[index],index)+recurse(coins,amount,index+1);

        }
        return dp[index][amount]=recurse(coins,amount,index+1);
    }
};