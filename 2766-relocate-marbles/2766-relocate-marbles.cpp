class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        unordered_map<int,int> mpp;
        for(auto it: nums){
            if(!mpp.count(it)){
                mpp[it]=1;

            }
        }
        for(int i=0;i<moveFrom.size();i++){
            if(mpp.count(moveFrom[i])){
                mpp.erase(moveFrom[i]);
                mpp[moveTo[i]]=1;
            }
        }
        vector<int> ans;
        for(auto it: mpp){
            ans.push_back(it.first);

        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};