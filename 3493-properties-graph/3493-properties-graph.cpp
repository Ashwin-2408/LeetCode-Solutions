class Solution {
public:
    int numberOfComponents(vector<vector<int>>& properties, int k) {
        vector<vector<int>> adj(properties.size());
        for(int i=0;i<properties.size();i++){
            for(int j=i+1;j<properties.size();j++){
                unordered_set<int> s(properties[i].begin(),properties[i].end());
                int count=0;
                for(auto it: properties[j]){
                    if(s.erase(it)){
                        count++;
                    }
                }
                if(count>=k){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<bool> visited(properties.size(),false);
        int connected_components=0;
        for(int i=0;i<properties.size();i++){
            if(visited[i]==false){
                visited[i]=true;
                connected_components++;
                queue<int> q;
                q.push(i);
                while(!q.empty()){
                    int node=q.front();
                    q.pop();
                    for(auto it:adj[node]){
                        if(!visited[it]){
                            visited[it]=true;
                            q.push(it);
                        }
                    }

                }
            }
        }
        return connected_components;
        
    }
};