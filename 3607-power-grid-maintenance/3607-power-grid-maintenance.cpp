

class Solution {
public:
    vector<int> parent;
    vector<set<int>> online;
    int find_parent(int p){
        if(parent[p]!=p){
            parent[p]= find_parent(parent[p]);
        }
        return parent[p];
    }
    void union_find(int u,int v){
        int up=find_parent(u);
        int vp=find_parent(v);
        if(up==vp){
            return;
        }
    
        if(online[up].empty() ||( !online[vp].empty() && *online[up].begin()>*online[vp].begin())){
            swap(up,vp);
        }
            parent[vp]=up;
            for(auto it: online[vp]){
                online[up].insert(it);
            }
            online[vp].clear();
            
        
    }
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        parent.resize(c+1);
        online.resize(c+1);
        for(int i=1;i<c+1;i++){
            parent[i]=i;
            online[i].insert(i);
        }
        for(auto it :connections){
            union_find(it[0],it[1]);
        }
        vector<int> ans;
        vector<bool> visited(c+1,false);
        for(auto it: queries){
            if(it[0]==1){
                if(visited[it[1]]==false){
                    ans.push_back(it[1]);
                    continue;
                }
                int parent=find_parent(it[1]);
                if(online[parent].empty()){
                    ans.push_back(-1);
                }
                else{
                    ans.push_back(*online[parent].begin());
                }
            }
            else{
                visited[it[1]]=true;
                int parent=find_parent(it[1]);
                online[parent].erase(it[1]);
            }
        }
        return ans;
        
    }
};