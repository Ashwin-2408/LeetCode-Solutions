class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> board(8,vector<int>(8,0));
        vector<vector<int>> ans;
        for(auto it:queens){
            board[it[0]][it[1]]=1;
        }
        board[king[0]][king[1]]=2;
        int i=king[0];
        int j=king[1];
        for(int k=i+1;k<8;k++){
            if(board[k][j]==1){
                ans.push_back({k,j});
                break;
            }
            
        }
        for(int k=i-1;k>=0;k--){
            if(board[k][j]==1){
                ans.push_back({k,j});
                break;
            }
            
        }
        
        for(int k=j+1;k<8;k++){
            if(board[i][k]==1){
                ans.push_back({i,k});
                break;
            }
            
        }
        for(int k=j-1;k>=8;k--){
            if(board[i][k]==1){
                ans.push_back({i,k});
                break;
            }
            
        }
        int k=i+1;
        int l=j+1;
        while(k<8 && l<8){
            if(board[k][l]==1){
                ans.push_back({k,l});
                break;
            }
            
            k++;
            l++;

        }
        k=i+1;
        l=j-1;
         while(k<8 && l>=0){
            if(board[k][l]==1){
                ans.push_back({k,l});
                break;
            }
            
            k++;
            l--;

        }
        k=i-1;
        l=j+1;
        while(k>=0 && l<8){
            if(board[k][l]==1){
                ans.push_back({k,l});
                break;
            }
            k--;
            l++;

        }
        k=i-1;
        l=j-1;
        while(k>=0 && l>=0){
            if(board[k][l]==1){
                ans.push_back({k,l});
                break;
            }
            k--;
            l--;

        }
        return ans;
    }
};