class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        map<int,int> mpp;
        for(int i=0;i<n;i++){
            mpp[i]=0;
        }
        for(auto it: edges){
            mpp[it[1]]++;
        }
        for(auto it: mpp){
            if(it.second==0){
                ans.push_back(it.first);
            }
        }
        return ans;
        
    }
};