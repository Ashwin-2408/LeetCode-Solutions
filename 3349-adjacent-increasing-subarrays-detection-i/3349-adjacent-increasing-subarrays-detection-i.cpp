class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        
        for(int i=0;i<nums.size()-k;i++){
            bool increasing=true;
            for(int j=i+1;j<i+k;j++){
                if(j==0){
                    continue;
                }
                if(nums[j-1]>=nums[j]){
                    increasing=false;
                    break;
                }
            }
            if(increasing){
                if(i+2*k-1>=nums.size()){
                    break;
                }
                bool increase=true;
                for(int j=i+k+1;j<i+2*k;j++){
                    if(nums[j-1]>=nums[j]){
                        increase=false;
                    }

                }
                if(increase){
                   
                    return true;
                }
            }
        }
        return false;
        
    }
};