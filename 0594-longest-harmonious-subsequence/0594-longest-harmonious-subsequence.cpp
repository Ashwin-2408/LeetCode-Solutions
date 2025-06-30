class Solution {
public:
    int findLHS(vector<int>& nums) {
        vector<int> mpp(*max_element(nums.begin(),nums.end())+1,0);
        for(auto it: nums){
            mpp[it]++;
        }
        int ans=0;
        for(int i=1;i<mpp.size();i++){
            if(mpp[i]!=0 && mpp[i-1]!=0){
                ans=max(ans,mpp[i]+mpp[i-1]);
            }
            else{
                continue;
            }
        }
        return ans;
    }
};