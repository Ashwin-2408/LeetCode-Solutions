class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int closest_sum=INT_MAX;
        int ans=INT_MAX;
        for(int i=0;i<nums.size()-2;i++){
           
            int j=i+1;
            int k=nums.size()-1;
            while(j<k){
                if(abs(nums[i]+nums[j]+nums[k]-target)<=closest_sum){
                    ans=nums[i]+nums[j]+nums[k];
                    closest_sum=abs(nums[i]+nums[j]+nums[k]-target);
                }
                if(nums[i]+nums[j]+nums[k]<target){
                    j++;
                }
                else{
                    k--;
                }
                
            }
        }
        return ans;
        
    }
};