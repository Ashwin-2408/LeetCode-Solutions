class Solution {
public:
    vector<vector<long long>> dp;
    long long maxScore(vector<int>& nums, int x) {
        int n=nums.size();
        dp.assign(n+1,vector<long long>(2,-1));
        int sign=0;
        if(nums[0]%2==0){
            sign=1;
        }
        return nums[0]+solve(nums,1,sign,x);
        
    }
    long long solve(vector<int>& nums,int i,int prev,int x){
        if(i>=nums.size()){
            return 0;
        }
        int sign=0;
        if(nums[i]%2==0){
            sign=1;
        }
        if(dp[i][prev]!=-1){
            return dp[i][prev];
        }
        else{
           
            if(prev==1 && nums[i]%2==0 || prev==0 && nums[i]%2==1 ){
                return dp[i][prev]=max(nums[i]+solve(nums,i+1,sign,x),solve(nums,i+1,prev,x));

            }
            else{
                return dp[i][prev]=max(nums[i]-x+solve(nums,i+1,sign,x),solve(nums,i+1,prev,x));

            }
        }

    }
};