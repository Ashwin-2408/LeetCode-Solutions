/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int,int> values;
        unordered_map<int,vector<int>> adj;
        for(auto it: employees){
            values[it->id]=it->importance;
            for(auto sub:it->subordinates){
                adj[it->id].push_back(sub);
            }
        }
        queue<int> q;
        q.push(id);
        int total_importance=0;

        while(!q.empty()){
            int curr_id=q.front();
            q.pop();
            total_importance+=values[curr_id];
            for(auto it:adj[curr_id]){
                q.push(it);
            }


        }
        return total_importance;

        
    }
};