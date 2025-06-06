class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps=0;
        int farthest=0;
        int curr_end=0;
        for(int i=0;i<nums.size()-1;i++){
            farthest=max(farthest,nums[i]+i);
            if(curr_end==i){
                jumps++;
                curr_end=farthest;
            }
        }
        return jumps;
    }


};