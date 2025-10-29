class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> xor_val(m,vector<int>(n,0));
        priority_queue<int,vector<int>,greater<int>> pq;
        xor_val[0][0]=matrix[0][0];
        pq.push(xor_val[0][0]);
        for(int i=1;i<n;i++){
            xor_val[0][i]=xor_val[0][i-1]^matrix[0][i];
            pq.push(xor_val[0][i]);
            while(pq.size()>k ){
                pq.pop();

            }
           


        }
        for(int i=1;i<m;i++){
            xor_val[i][0]=xor_val[i-1][0]^matrix[i][0];
            pq.push(xor_val[i][0]);
            while(pq.size()>k){
                pq.pop();

            }
            


        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                xor_val[i][j]=matrix[i][j]^xor_val[i-1][j]^xor_val[i][j-1]^xor_val[i-1][j-1];
                pq.push(xor_val[i][j]);
                while(pq.size()>k){
                    pq.pop();

                }
                
            }
        }
        return pq.top();
        
    }
};