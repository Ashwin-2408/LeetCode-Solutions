class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(),false);
        queue<int> q;
        q.push(0);

        while(!q.empty()){
            int node=q.front();
            q.pop();
            visited[node]=true;
            for(auto it: rooms[node]){
                if(visited[it]==false){
                    q.push(it);
                }
            }

        }
        for(int i=0;i<rooms.size();i++){
            if(visited[i]==false){
                return false;
            }
        }
        return true;
        
    }
};