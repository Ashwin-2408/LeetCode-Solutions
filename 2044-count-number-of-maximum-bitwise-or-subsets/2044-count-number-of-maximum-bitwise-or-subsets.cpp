class Solution {
public:
    int ans=0;
    int countMaxOrSubsets(vector<int>& nums) {
        int maximum_bitwise=nums[0];
        for(int i=1;i<nums.size();i++){
            maximum_bitwise=maximum_bitwise|nums[i];
        }
        recurse(nums,0,0,maximum_bitwise);
        return ans;
        
    }
    void recurse(vector<int>&nums,int i,int ored,int target){
        if(i==nums.size()){
            return;
        }
        if((ored|nums[i])==target){
            ans++;
        }
        recurse(nums,i+1,ored,target);
        recurse(nums,i+1,ored|nums[i],target);

    }
};