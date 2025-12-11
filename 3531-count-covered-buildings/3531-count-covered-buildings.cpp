class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int,int> row_max;
        unordered_map<int,int> row_min;
        unordered_map<int,int> col_max;
        unordered_map<int,int> col_min;
        
        for(int i=0;i<buildings.size();i++){
            int x=buildings[i][0];
            int y=buildings[i][1];
            if(row_max.count(x)){
                row_max[x]=max(y,row_max[x]);
                
            }
            else{
                row_max[x]=y;
            }
            if(row_min.count(x)){
                row_min[x]=min(y,row_min[x]);
            }
            else{
                row_min[x]=y;
            }
            if(col_max.count(y)){
                col_max[y]=max(x,col_max[y]);
            }
            else{
                col_max[y]=x;
            }
            if(col_min.count(y)){
                col_min[y]=min(x,col_min[y]);
            }
            else{
                col_min[y]=x;
            }
        }
        int ans=0;
        for(auto it: buildings){
            int x=it[0];
            int y=it[1];
            int up=row_min[x];
            int down=row_max[x];
            int right=col_max[y];
            int left=col_min[y];
            
            
            if(y<down && y>up && x<right && x>left){
                ans++;
            }

        }
        
        return ans;
       
        

        
    }
};