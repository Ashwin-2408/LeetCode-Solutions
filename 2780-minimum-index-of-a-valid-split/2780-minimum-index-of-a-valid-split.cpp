class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        map<int,int> mpp;
        for(auto it: nums){
            mpp[it]++;
        }
        int max_ele=-1;
        int max_count=0;
        for(auto it: mpp){
            if(it.second>max_count){
                max_count=it.second;
                max_ele=it.first;
            }
        }
        int curr_count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==max_ele){
                curr_count++;
            }
            if((curr_count*2) > (i+1)  && ((max_count-curr_count)*2)>(nums.size()-i-1) ){
                return i;
            }

        }
        return -1;
    }
};