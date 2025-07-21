class Solution {
public:
    static bool comparator(pair<string,int>&a,pair<string,int>&b){
        if(a.second==b.second){
            return a.first<b.first;
        }
        else{
            return a.second <b.second;
        }
    }
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
       
        map<string,int> mpp;
        vector<vector<int>> adj(friends.size());
        for(int i=0;i<friends.size();i++){
            for(int j=0;j<friends[i].size();j++){
                adj[i].push_back(friends[i][j]);
            }
        }
        queue<pair<int,int>> q;
        q.push({id,0});
        vector<bool> visited(friends.size(),false);
        visited[id]=true;
        while(!q.empty()){
            int node=q.front().first;
            int lev=q.front().second;
            q.pop();
            if(lev==level){
                for(auto it: watchedVideos[node]){
                    mpp[it]++;
                }
            }
            else if(lev<level){
                
                for(auto it: adj[node]){
                    if(visited[it]==false){
                    q.push({it,lev+1});
                    }
                }
            }

        }
        vector<pair<string,int>> vec_map(mpp.begin(),mpp.end());
        sort(vec_map.begin(),vec_map.end(),comparator);
        vector<string > ans;
        for(auto it:vec_map){
            ans.push_back(it.first);
        }
        
        return ans;
    }
};