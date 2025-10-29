class Solution {
public:
    vector<vector<int>> dp;
    int maxSumDivThree(vector<int>& nums) {
        dp.resize(nums.size(),vector<int>(3,-1));
        return solve(0,nums,0);
        
    }
    int solve(int i,vector<int> & nums,int sum){
        if(i==nums.size() && sum%3==0){
            return 0;
        }
        if(i>=nums.size()){
            return INT_MIN;
        }
        int rem=sum%3;
        if(dp[i][rem]!=-1){
            return dp[i][rem];
        }
        int ans=max(nums[i]+solve(i+1,nums,sum+nums[i]),solve(i+1,nums,sum));
        return dp[i][rem]=ans;
    }
};