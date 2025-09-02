class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int ans=0;
        for(int i=0;i<points.size();i++){
            for(int j=0;j<points.size();j++){
                if(i==j){
                    continue;
                }
                int Ax=points[i][0];
                int Ay=points[i][1];
                int Bx=points[j][0];
                int By=points[j][1];
                bool valid=true;
                if(Ax<=Bx && Ay>=By){
                    for(int k=0;k<points.size();k++){
                        int Cx=points[k][0];
                        int Cy=points[k][1];
                        if(k==i || k==j){
                            continue;
                        }
                        
                        else{
                            if(Cx>=Ax && Cx<=Bx && Cy>=By && Cy<=Ay){
                                valid=false;
                                break;
                            }
        
                        }
                    }
                    if(valid){
                    ans++;
                }
                }
                
            }
        }
        return ans;
        
    }
};