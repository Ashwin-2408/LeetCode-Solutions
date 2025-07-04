class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        for(int i=nums.size()-1;i>0;i--){
            if(nums[i]>=nums[i-1]){
                nums[i-1]+=nums[i];
            }

        }
        return nums[0];
    }
};