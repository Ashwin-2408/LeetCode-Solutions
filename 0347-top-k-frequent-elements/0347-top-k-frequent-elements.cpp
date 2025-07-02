class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>> pq;
        unordered_map<int,int> mpp;
        for(auto it: nums){
            mpp[it]++;
        }
        for(auto it: mpp){
            pq.push({it.second,it.first});
        }
        vector<int> ans;
        while(k>0){
            k--;
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
        
    }
};