class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int partition_first_element = nums[0];
        int ans=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]-partition_first_element<=k){
                continue;
            }
            else{
                ans++;
                partition_first_element=nums[i];
            }
        }
        return ans+1;
        
    }
};