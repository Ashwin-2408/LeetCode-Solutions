class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int ans=0;
        for(auto it:nums){
            if(it%2==0){
                ans+=it;
            }
        }
        vector<int> arr;
        for(auto it: queries){
            if((nums[it[1]]+it[0])%2==0){
                if(nums[it[1]]%2==0){
                    ans+=it[0];
                }
                else{
                    ans+=nums[it[1]]+it[0];
                }
            }
            else{
                if(nums[it[1]]%2==0){
                ans-=nums[it[1]];
                }
                
            }
            arr.push_back(ans);
            nums[it[1]]+=it[0];
        }
        return arr;
        
    }
};