class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        unordered_map<int,int> mpp;
        for(auto it: roads){
            mpp[it[0]]++;
            mpp[it[1]]++;
        }
        vector<pair<int,int>> combined;
        for(auto it: mpp){
            combined.push_back({it.second,it.first});
        }
        sort(combined.begin(),combined.end(),greater<>());
        vector<int> scores(n);
        int val=n;
        for(auto it:combined){
            scores[it.second]=val;
            val--;

        }
        long long ans=0;
        for(auto it: roads){
            ans+=scores[it[0]];
            ans+=scores[it[1]];

        }
        return ans;


        
    }
};