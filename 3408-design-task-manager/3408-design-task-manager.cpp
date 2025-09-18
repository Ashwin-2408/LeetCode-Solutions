class TaskManager {
public:
    unordered_map<int,int> user_task_mpp;
    unordered_map<int,int> task_priority_mapping;
    priority_queue<pair<int,int>> pq;
    TaskManager(vector<vector<int>>& tasks) {
        for(auto it: tasks){
            add(it[0],it[1],it[2]);
        }
        
    }
    
    void add(int userId, int taskId, int priority) {
        user_task_mpp[taskId]=userId;
        task_priority_mapping[taskId]=priority;
        pq.push({priority,taskId});

        
    }
    
    void edit(int taskId, int newPriority) {
        task_priority_mapping[taskId]=newPriority;
        pq.push({newPriority,taskId});
        
    }
    
    void rmv(int taskId) {
        task_priority_mapping.erase(taskId);
        
    }
    
    int execTop() {
        auto it=pq.top();
        while(!pq.empty() && (!task_priority_mapping.count(it.second) || it.first!=task_priority_mapping[it.second])){
            
            pq.pop();
            it=pq.top();
        }
        if(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int top_val=user_task_mpp[it.second];
            task_priority_mapping.erase(it.second);
            return top_val;

        }
        return -1;
        
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */