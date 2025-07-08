class Solution {
public:
    vector<vector<int>> dp;
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        dp.resize(n+1,vector<int>(n+1,-1));
        int ans=solve(nums,0,-1);
        return ans;
    }
    int solve(vector<int> & nums,int curr,int prev){
        if(curr>=nums.size()){
            return 0;
        }
        if(dp[curr+1][prev+1]!=-1){
            return dp[curr+1][prev+1];
        }
        int take=0;
        int dont_take=0;
        if(prev==-1 || nums[curr]>nums[prev]){
            take=1+solve(nums,curr+1,curr);
            dont_take=solve(nums,curr+1,prev);
            return dp[curr+1][prev+1]= max(take,dont_take);
        }
        else{
            dont_take=solve(nums,curr+1,prev);
            return dp[curr+1][prev+1]=max(take,dont_take);

        }


    }
};