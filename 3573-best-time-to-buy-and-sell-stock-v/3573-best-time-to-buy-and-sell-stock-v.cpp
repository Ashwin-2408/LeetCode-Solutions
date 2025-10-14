class Solution {
public:
    vector<vector<vector<long long>>> dp;
    long long maximumProfit(vector<int>& prices, int k) {
        dp.assign(prices.size(),vector<vector<long long>>(k+1,vector<long long>(3,-1)));
        return solve(prices,0,k,0);
        
    }
    long long solve(vector<int> & prices,int i , int k ,int state){
        if(k==0 ||i>=prices.size()){
            return 0;
        }
        if(dp[i][k][state]!=-1){
            return dp[i][k][state];
        }
        if(i==prices.size()-1){
            if(state==1){
                return prices[i];
            }
            else if(state==2){
                return -prices[i];
            }
            else{
                return 0;
            }
        }
        if(state==0){
            return dp[i][k][state]=max({solve(prices,i+1,k,1)-prices[i],solve(prices,i+1,k,2)+prices[i],solve(prices,i+1,k,0)});
        }
        else if(state==1){
            return dp[i][k][state]=max(solve(prices,i+1,k-1,0)+prices[i],solve(prices,i+1,k,1));
        }
        else{
            return dp[i][k][state]=max(solve(prices,i+1,k-1,0)-prices[i],solve(prices,i+1,k,2));
        }
    }
};