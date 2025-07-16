class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int even=0;
        int odd=0;
        for(auto it: nums){
            if(it%2==0){
                even++;
            }
            else{
                odd++;
            }
        }
        return max({recurse(nums,0,-1),even,odd});
        
    }
    int recurse(vector<int>&nums,int i,int sign){
        if(i==nums.size()){
            return 0;
        }
        if(i==-1){
            sign=nums[i]%2;
            return 1+recurse(nums,i+1,sign);
        }
        else{
            if(nums[i]%2!=sign){
                return 1+recurse(nums,i+1,nums[i]%2);
            }
            else{
                return recurse(nums,i+1,sign);

            }
        }
      
    }
};