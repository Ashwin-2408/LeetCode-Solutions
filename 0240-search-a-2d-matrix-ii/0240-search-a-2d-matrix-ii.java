class Solution {
    public boolean searchMatrix(int[][] matrix,int target) {
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0 ) return false;
        int i = 0 ;
        int j = matrix[0].length - 1 ;
        while (i < matrix.length && j >= 0){
            int element = matrix[i][j];
            if (element == target) return true;
            else if (element > target) j--;
            else i ++;

        }
        return false;
    }
}