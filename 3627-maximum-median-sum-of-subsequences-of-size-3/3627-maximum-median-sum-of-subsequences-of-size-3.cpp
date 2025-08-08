class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0;
        int j=nums.size()-1;
        long long ans=0;
        while(i<j){
        
        
                ans+=nums[j-1];
                j-=2;
                i++;
            
        }
        return ans;
        
    }
};