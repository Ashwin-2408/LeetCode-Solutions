class Solution {
public:
    
    vector<pair<int,int>> dir={{-1,0},{1,0},{0,1},{0,-1}};
    int countBattleships(vector<vector<char>>& board) {
        int count=0;
        int n=board.size();
        int m=board[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='X' && visited[i][j]==false){
                    count++;
                    dfs(board,visited,i,j);

                }
            }
        }
        return count;
        
        
    }
    void dfs(vector<vector<char>>& board,vector<vector<bool>>&visited,int i,int j){
        int n=board.size();
        int m=board[0].size();
        if(board[i][j]=='.'){
            return;
        }
        visited[i][j]=true;
        for(auto it:dir){
            int new_x=it.first+i;
            int new_y=it.second+j;
            if(new_x>=0 && new_x<n && new_y>=0 && new_y<m && visited[new_x][new_y]!=true){
                dfs(board,visited,new_x,new_y);
            }
        }
    }
};