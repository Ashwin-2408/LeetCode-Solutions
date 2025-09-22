class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int max_freq=0;
        unordered_map<int,int> mpp;
        for(auto it: nums){
            mpp[it]++;
            if(mpp[it]>max_freq){
                max_freq=max(mpp[it],max_freq);
            }
        }
        int ans=0;
        for(auto it: mpp){
            if(it.second==max_freq){
                ans+=max_freq;
            }

        }
        return ans;
    }
};