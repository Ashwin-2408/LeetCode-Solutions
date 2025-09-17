class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int low=matrix[0][0];
        int high=matrix[n-1][n-1];
        while(low <high){
            int mid= low + (high-low)/2;
            if(countless(matrix,mid)<k){
                low=mid+1;
            }
            else{
                high=mid;
            }
        }
        return low;
        
    }
    int countless(vector<vector<int>> & matrix,int k){
        int row=matrix.size()-1;
        int col=0;
        int count=0;
        while(row>=0 && col<matrix.size()){
            if(matrix[row][col]<=k){
                count+=(row+1);
                col++;
            }
            else{
                row--;
            }
        }
        return count;
    }
};