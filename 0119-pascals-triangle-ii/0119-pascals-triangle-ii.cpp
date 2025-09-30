class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex==0){
            return {1};
        }
        
        return solve(0,rowIndex,{1});
        
        
        
    }
    vector<int> solve(int curr_row,int target_row,vector<int> arr){
        if(target_row==curr_row){
            return arr;
        }
        vector<int> temp;
        temp.push_back(arr[0]);
        for(int i=1;i<arr.size();i++){
            temp.push_back(arr[i]+arr[i-1]);

        }
        temp.push_back(arr[arr.size()-1]);
        return solve(curr_row+1,target_row,temp);
    }
};