class Solution {
public:
    int specialPerm(vector<int>& nums) {
        int mode=1e9+7;
        int n=nums.size();
        int mask=1 << n;
        vector<vector<long long>> dp (mask,vector<long long>(n,-1));
        long long total=0;

        for(int i=0;i<n;i++){
    
            total=(total+generator(nums,1<<i,i,dp))%mode;

        }
        return total;
        
    }
    long long generator(vector<int>& nums,int mask,int last_index,vector<vector<long long>>& dp){
        int mode=1e9+7;
        int n=nums.size();
        if(mask==(1<<n) -1){
            return 1;
        }
        if(dp[mask][last_index]!=-1){
            return dp[mask][last_index];
        }
        long long total=0;
        for(int i=0;i<n;i++){
            if(mask & (1<<i)){
                continue;
            }
            if(nums[i]%nums[last_index]==0 || nums[last_index]%nums[i]==0){
            total=(total+generator(nums,mask|(1<<i),i,dp))%mode;
            }
            
        }
        return dp[mask][last_index]=total;
    }
};