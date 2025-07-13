class Disjoint_Set{
    public:
    vector<int> rank,parent;
    Disjoint_Set(int n){
        rank.resize(n,0);
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int find_parent(int x){
        if(parent[x]!=x){
            return parent[x]=find_parent(parent[x]);
        }
        return parent[x];
    }
    bool union_find(int x,int y){
        int x_par=find_parent(x);
        int y_par=find_parent(y);
        if(x_par==y_par){
            return false;
        }
        else{
            if(rank[x_par]>rank[y_par]){
                parent[y_par]=x_par;
            }
            else if(rank[x_par]<rank[y_par]){
                parent[x_par]=y_par;
            }
            else{
                parent[y_par]=x_par;
                rank[x_par]++;

            }
        }
    return true;
    }
    
};

class Solution {
public:
    static bool comparator(vector<int>&a ,vector<int>&b){
        return a[2]<b[2];
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>> edges;
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                int distance=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                edges.push_back({i,j,distance});
            }
        }
        sort(edges.begin(),edges.end(),comparator);
        Disjoint_Set ds(points.size());
        int ans=0;
        for(auto it: edges){
            if(ds.union_find(it[0],it[1])){
                ans+=it[2];
            }
        }
        return ans;


        
    }
};