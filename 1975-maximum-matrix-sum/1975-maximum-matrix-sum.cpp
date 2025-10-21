class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int minimum_value=INT_MAX;
        int neg_count=0;
        int n=matrix.size();
        long long ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]<0){
                    neg_count++;
                }
                minimum_value=min(minimum_value,abs(matrix[i][j]));
                ans+=abs(matrix[i][j]);
            }
        }
        if(neg_count%2==0){
            return ans;
        }
        else{
            return ans-2*minimum_value;
        }
        
    }
};