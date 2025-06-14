class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0;i<n;i++){
            int j=0;
            while(j<=i){
                int temp=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=temp;
                j++;

            }
            continue;
          
        }
        for(auto &it : matrix){
            reverse(it.begin(),it.end());
        }
        
    }
};