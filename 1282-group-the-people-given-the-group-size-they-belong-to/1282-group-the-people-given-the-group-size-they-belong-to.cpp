class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        map<int,vector<int>> mpp;
        for(int i=0;i<groupSizes.size();i++){
            mpp[groupSizes[i]].push_back(i);
        }
        vector<vector<int>> ans;
        for(auto it: mpp){
            int cap_size=it.first;
            int curr_size=it.second.size();
            if(curr_size<=cap_size){
                ans.push_back(it.second);
            }
            else{
                vector<int> temp;
                int i=0;
                while(i<curr_size){
                    temp.push_back(it.second[i]);
                    if(temp.size()==cap_size){
                        ans.push_back(temp);
                        temp.clear();
                    }
                    i++;
                }
            }
        }
        return ans;
        
    }
};