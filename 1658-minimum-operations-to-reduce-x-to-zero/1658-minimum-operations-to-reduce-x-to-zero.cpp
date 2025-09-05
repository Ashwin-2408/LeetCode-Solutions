class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total=accumulate(nums.begin(),nums.end(),0);
        int target=total-x;
        int l=0;
        int r=0;
        int curr_sum=0;
        int ans=INT_MAX;
        while(r<nums.size()){
            curr_sum+=nums[r];
            while(curr_sum>target && l<=r){
                curr_sum-=nums[l];
                l++;
            }
            if(curr_sum==target){
                ans=min(ans,(int)nums.size()-(r-l+1));
            }
            r++;


        }
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
        
    }
};