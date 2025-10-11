class Solution {
public:
    vector<int> dp;
    int maximumJumps(vector<int>& nums, int target) {
        dp.assign(nums.size(),-1);
        return solve(nums,0,target)==INT_MIN ? -1 :solve(nums,0,target);
        
    }
    int solve(vector<int>& nums,int i,int target){
        if(i==nums.size()-1){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int ans=INT_MIN;
        for(int k=i+1;k<nums.size();k++){
            if(abs(nums[i]-nums[k])<=target){
                int next=solve(nums,k,target);
                if(next!=INT_MIN){
                    ans=max(ans,1+next);
                }
            }   
        }
        return dp[i]=ans;
    
    }
};