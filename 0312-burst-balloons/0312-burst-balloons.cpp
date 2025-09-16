class Solution {
public:
    vector<vector<int>> dp;
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        reverse(nums.begin(),nums.end());
        nums.push_back(1);
        reverse(nums.begin(),nums.end());
        int i=1;
        int maximum=INT_MIN;
        int j=nums.size()-2;
        dp.resize(nums.size(),vector<int>(nums.size(),-1));
        recurse(i,j,nums);
      
        for(auto it: dp){
            for(auto ele:it){
                maximum=max(maximum,ele);
            }
        }
        return maximum;
        
    }
    int recurse(int i,int j,vector<int>& nums){
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int maximum=INT_MIN;
        for(int k=i;k<=j;k++){
            int val=nums[i-1]*nums[k]*nums[j+1];
            maximum=max(maximum,recurse(i,k-1,nums)+val+recurse(k+1,j,nums));
        }
        return dp[i][j]=maximum;
    }
};