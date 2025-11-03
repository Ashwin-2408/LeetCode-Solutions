class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> degree(numCourses,0);
        for(auto it: prerequisites){
            adj[it[0]].push_back(it[1]);
            degree[it[1]]++;

        }

        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(degree[i]==0){
                q.push(i);
            }
        }
        vector<int> topo;
        while(!q.empty()){
            int node=q.front();
            topo.push_back(node);
            q.pop();
            for(auto it: adj[node]){
                degree[it]--;
                if(degree[it]==0){
                    q.push(it);
                }
            }

        }
        if(topo.size()==numCourses){
            return true;
        }
        else{
            return false;
        }
        
       
        
    }
};