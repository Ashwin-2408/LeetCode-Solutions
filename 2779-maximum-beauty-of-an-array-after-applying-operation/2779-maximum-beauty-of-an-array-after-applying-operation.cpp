class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i=0;
        int length=1;
        int j=nums.size()-1;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[j]-nums[i]<=2*k){
                length=max(length,j-i+1);
            }
                
            }
        }
        return length;
       
    }
};