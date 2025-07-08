class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,pair<int,int>> mpp;
        for(auto it : matches){
            mpp[it[0]].first++;
            mpp[it[1]].second++;
        }
        vector<int> list1;
        vector<int> list2;
        for(auto it : mpp){
            if(it.second.second==0){
                list1.push_back(it.first);
            }
            else if(it.second.second==1){
                list2.push_back(it.first);
            }
        }
        return {list1,list2};
    }
};