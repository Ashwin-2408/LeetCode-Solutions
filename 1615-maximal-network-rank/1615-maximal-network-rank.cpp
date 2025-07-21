class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> indegree(n);
        map<int,vector<int>> mpp;
        for(auto it: roads){
            mpp[it[0]].push_back(it[1]);
            mpp[it[1]].push_back(it[0]);
            indegree[it[0]]++;
            indegree[it[1]]++;
        }
        int max_rank=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(find(mpp[i].begin(),mpp[i].end(),j)!=mpp[i].end()){
                    max_rank=max(max_rank,indegree[i]+indegree[j]-1);
                }
                else{
                    max_rank=max(max_rank,indegree[i]+indegree[j]);

                }
            }
        }
        return max_rank;
        
    }
};