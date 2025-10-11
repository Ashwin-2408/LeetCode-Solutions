class Solution {
public:
    vector<long long> dp;
    long long solve(vector<int>& power, int i, unordered_map<int,int> &mpp){
        if(i>=power.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        auto it=lower_bound(power.begin(),power.end(),power[i]+3);
        int index=it-power.begin();
        long long pick=1LL*power[i]*mpp[power[i]]+solve(power,index,mpp);
        long long dont_pick=solve(power,i+1,mpp);
        return dp[i]=max(pick,dont_pick);
    }
    long long maximumTotalDamage(vector<int>& power) {
        dp.assign(power.size(),-1);
        unordered_map<int,int> mpp;
        for(auto it: power){
            mpp[it]++;
        }
        sort(power.begin(),power.end());
        return solve(power,0,mpp);
        

        
    }
};