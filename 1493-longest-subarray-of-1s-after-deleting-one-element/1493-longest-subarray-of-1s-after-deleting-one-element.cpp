class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l=0;
        int r=0;
        int count=0;
        int ans=0;
        int zero_count=0;
        bool zero=false;
        while(r<nums.size()){
            if(nums[r]==1){
                count++;
            }
            else if(nums[r]==0){
                zero_count++;
                zero=true;
            }
            while(zero_count>1 && l<r){
                if(nums[l]==0){
                    zero_count--;
                }
                else{
                    count--;
                }
                l++;
            }
            r++;
            ans=max(count,ans);

        }
        if(zero){
            return ans;
        }
        else{
            return max(0,ans-1);
        }
        
    }
};