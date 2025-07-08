class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod_without_zero=1;
        int zero=0;
        for(auto it: nums){
            if(it!=0){
                prod_without_zero*=it;
            }
            else{
                zero++;
               
            }
        }
        vector<int> ans(nums.size(),0);
        if(zero>1){
            return ans;

        }
        else{
            if(zero==1){
            for(int i=0;i<nums.size();i++){
                if(nums[i]!=0){
                    ans[i]=0;
                }
                else{
                    ans[i]=prod_without_zero;
                }

            }
            }
            else{
                for(int i=0;i<nums.size();i++){
                    ans[i]=prod_without_zero/nums[i];
               

                }

            }
            return ans;
        }
        return ans;
        
        
    }
};