class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int i=0;
        int j=0;
        int m=mat.size();
        int n=mat[0].size();
        vector<int> ans;
        bool down=false;
        while(ans.size()<m*n && i<m && j<n){
            ans.push_back(mat[i][j]);
            if(!down && i-1>=0 && j+1<n ){
                i=i-1;
                j=j+1;
            }
            else if(down && j-1>=0 && i+1<m ){
                j=j-1;
                i=i+1;
            }
            else if(!down){
                if(j==n-1){
                    i=i+1;
                }
                else if(i==0){
                    j=j+1;
                }
               
                down=!down;
            }
            else{
                if(i==m-1){
                    j=j+1;

                }
                else if(j==0){
                    i=i+1;
                }
                 
                down=!down;
            }
            


        }
        return ans;
        
    }
};