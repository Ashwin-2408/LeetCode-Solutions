class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int left=*max_element(nums.begin(),nums.end());
        int right=accumulate(nums.begin(),nums.end(),0);
        while(left<right){
            int mid = left+ (right-left)/2;
            if(valid(nums,mid,k)){
                right=mid;
            }
            else{
                left=mid+1;
            }

        }
        return left;

        
    }
    bool valid(vector<int> & nums,int val, int k){
        int split=1;
        int curr_sum=0;
        for(int i=0;i<nums.size();i++){
            if(curr_sum+nums[i]>val){
                curr_sum=nums[i];
                split++;
            }
            else{
                curr_sum+=nums[i];
            }
        }
        if(split<=k){
            return true;
        }
        return false;

    }
};