class Solution {
public:
    int generate_number(int n,int r){
        
        int res=1;
        for(int i=0;i<r;i++){
            
            res=res*(n-i);
            res=res/(i+1);
        }
        return res;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i =0;i<numRows;i++){
            vector<int> row(i+1);
            for(int j=0;j<i+1;j++){
                int x=generate_number(i,j);
                row[j]=x;

            }
            ans.push_back(row);
        }
        return ans;

        
    }
};