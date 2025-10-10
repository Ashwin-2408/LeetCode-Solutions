class Solution {
public:
    vector<int> dp;
    int maximumEnergy(vector<int>& energy, int k) {
        dp.assign(energy.size(),-1);
        int ans=INT_MIN;

        for(int i=0;i<energy.size();i++){
            ans=max(ans,solve(energy,i,k));
        }
        return ans;

        
    }
    int solve(vector<int>& energy,int i,int k){
        if(i+k>=energy.size()){
            return dp[i]=energy[i];
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        return dp[i]=energy[i]+solve(energy,i+k,k);

    }

};