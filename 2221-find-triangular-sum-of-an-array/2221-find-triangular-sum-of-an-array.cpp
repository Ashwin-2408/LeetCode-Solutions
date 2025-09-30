class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int i=0;
        while(nums.size()!=1){
            vector<int> temp;
            i=0;
            while(i<nums.size()-1){
                temp.push_back((nums[i]+nums[i+1])%10);
                i++;
            }
            nums=temp;
           
        }
        return nums[0];
    }
};