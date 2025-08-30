class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> check(10,0);
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='.'){
                    continue;
                }
                if(check[board[i][j]-'0']==1){
                    return false;
                }
                else{
                    check[board[i][j]-'0']++;
                }

            }
            fill(check.begin(),check.end(),0);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[j][i]=='.'){
                    continue;
                }
                if(check[board[j][i]-'0']==1){
                    return false;
                }
                else{
                    check[board[j][i]-'0']++;
                }

            }
            fill(check.begin(),check.end(),0);
        }
        for(int startrow=0;startrow<=3;startrow++){
            for(int startcol=0;startcol<=3;startcol++){
                int row=startrow*3;
                int col=startcol*3;
                for(int i=0;i<3;i++){
                    for(int j=0;j<3;j++){
                        char val=board[row+i][col+j];
                        if(val=='.'){
                            continue;
                        }
                        else if(check[val-'0']==1){
                            return false;
                        }
                        else{
                            check[val-'0']++;
                        }
                    }
                }
                fill(check.begin(),check.end(),0);

            }
        }
        return true;

        
    }
};