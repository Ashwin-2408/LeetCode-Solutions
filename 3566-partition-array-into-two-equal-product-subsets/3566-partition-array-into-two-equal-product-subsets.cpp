typedef __int128 ll;

class Solution {
public:
    bool check(vector<int> & nums,int index,long long target, long double product){
        if(product==target){
            return true;
        }
        if(product>target || index>=nums.size()){
            return false;
        }
        if(check(nums,index+1,target,product)){
            return true;

        }
        if(check(nums,index+1,target,product*nums[index])){
            return true;
        }
        return false;
    }
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        ll product=1;
        ll maximum=(ll)target*target;
        for(auto it: nums){
            product=product*it;
            if(product >maximum){
                return false;
            }
        }
        if(product!=maximum){
            return false;
        }
        return check(nums,0,target,1);
        
    }
};