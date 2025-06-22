class Solution {
public:
    vector<int> findCoins(vector<int>& numWays) {
       
        vector<int> coins;
        for(int i=0;i<numWays.size();i++){
            if(enough_coins(coins,i+1)!=numWays[i]){
                coins.push_back(i+1);
                if(enough_coins(coins,i+1)!=numWays[i]){
                    return {};
                }
            }
            else{
                continue;
            }
        }
        return coins;
        
    }
    int enough_coins(vector<int>& coins,int amount){
      
        
        vector<vector<int>> dp(coins.size()+1,vector<int>(amount+1,0));
        dp[0][0]=1;
        for(int i=0;i<coins.size()+1;i++){
            dp[i][0]=1;
        }
        for(int i=1;i<coins.size()+1;i++){
            for(int j=1;j<amount+1;j++){
                if(j>=coins[i-1]){
                    
                   dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];;
                }
                else{
                    dp[i][j]=dp[i-1][j];
                    
                }
            }
        }
        return dp[coins.size()][amount];
        
            
        
    }
};