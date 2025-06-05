class Disjoint_Set{
    public:
        vector<int> parent;
        vector<int> rank;
    Disjoint_Set(int n){
        parent.resize(n+1,0);
        rank.resize(n+1,0);
        for(int i=0;i<n+1;i++){
            parent[i]=i;
        }
    }

    int find_par(int u){
        if(parent[u]==u){
            return u;
        }
        return parent[u]=find_par(parent[u]);
    }
    void union_by_rank(int u,int v){
        int up=find_par(u);
        int vp=find_par(v);
        if(up==vp){
            return;
        }
        else{
            if(rank[up]<rank[vp]){
                parent[up]=vp;
            }
            else if(rank[up]>rank[vp]){
                parent[vp]=up;
            }
            else{
                parent[up]=vp;
                rank[vp]++;
            }
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        Disjoint_Set ds(edges.size());
        for(auto it :edges){
            if(ds.find_par(it[0])==ds.find_par(it[1])){
                return {it[0],it[1]};
            }
            else{
                ds.union_by_rank(it[0],it[1]);
            }
        }
        return {};
    }
};