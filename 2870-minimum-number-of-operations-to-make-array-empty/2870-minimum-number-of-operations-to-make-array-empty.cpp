class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(auto it: nums){
            mpp[it]++;

        }
        int ans=0;
        for(auto &it: mpp){
            if(it.second%3==0){
                ans+=it.second/3;
                it.second=it.second%3;
            }
            else if(it.second%3==2){
                ans+=it.second/3;
                it.second=2;
            }
        }
        for(auto it: mpp){
            if(it.second%2==0){
                ans+=it.second/2;
            }
            else{
                return -1;
            }
        }
        return ans;
        
    }
};