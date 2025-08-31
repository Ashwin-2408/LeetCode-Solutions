class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        vector<int> ans;
        for(auto it: order){
            if(find(friends.begin(),friends.end(),it)!=friends.end()){
                ans.push_back(it);
            }
        }
        return ans;
        
    }
};