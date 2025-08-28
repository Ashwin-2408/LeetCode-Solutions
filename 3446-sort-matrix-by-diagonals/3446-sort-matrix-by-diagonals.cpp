class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n=grid.size()-1;
        int m=grid.size()-1;
        int n1=grid.size();
        while(n>=0){
            vector<int> temp;
            int i=n;
            int j=0;
            while(i<n1 && j<n1){
                temp.push_back(grid[i][j]);
                i++;
                j++;
            }
            sort(temp.begin(),temp.end(),greater<int>());
            i=n;
            j=0;
            int k=0;
            while(i<n1 && j<n1){
                grid[i][j]=temp[k];
                i++;
                j++;
                k++;
            }
            n--;
        }
        while(m>0){
            int i=0;
            int j=m;
            vector<int> temp;
            while(i<n1 && j<n1){
                temp.push_back(grid[i][j]);
                i++;
                j++;
            }
            sort(temp.begin(),temp.end());
            i=0;
            j=m;
            int k=0;
            while(i<n1 && j<n1){
                grid[i][j]=temp[k];
                i++;
                j++;
                k++;
            }
            m--;
        }
        return grid;
        
    }
};