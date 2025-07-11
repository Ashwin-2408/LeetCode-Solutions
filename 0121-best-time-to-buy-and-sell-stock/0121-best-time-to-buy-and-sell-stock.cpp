class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> minimum(prices.size());
        int mini=INT_MAX;
        minimum[0]=mini;
        for(int i=1;i<prices.size();i++){
            if(prices[i-1]<mini){
                mini=prices[i-1];
            }
            minimum[i]=mini;
        }
        int ans=0;
        for(auto it: minimum){
            cout << it;
        }
        for(int i=0;i<prices.size();i++){
            ans=max(ans,prices[i]-minimum[i]);
        }
        return ans;

        
    }
};