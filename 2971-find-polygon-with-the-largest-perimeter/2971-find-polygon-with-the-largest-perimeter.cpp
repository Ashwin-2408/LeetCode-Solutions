class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long ans=-1;
        long long curr_sum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<curr_sum && i>=2){
                ans=curr_sum+nums[i];

            }
            curr_sum+=nums[i];
        }
        return ans;
        
    }
};