class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=n-1;i>=0;i--){
            int j=i;
            int k=0;
            while(j<n && k<m){
                pq.push(mat[j][k]);
                j++;
                k++;


            }
            j=i;
            k=0;
            while(j<n && k<m){
                mat[j][k]=pq.top();
                pq.pop();
                j++;
                k++;
            }
            
        }
        for(int i=1;i<m;i++){
            int j=i;
            int k=0;
           
            while(k<n && j<m){
                pq.push(mat[k][j]);
                k++;
                j++;
                
            }
            j=i;
            k=0;
            while(k<n && j<m){
                mat[k][j]=pq.top();
                pq.pop();
                k++;
                j++;
            }
        }
        return mat;
        
        
    }
};