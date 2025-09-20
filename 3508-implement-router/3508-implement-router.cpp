class Router {
public:
    queue<vector<int>> q;
    set<vector<int>> s;
    unordered_map<int,vector<int>> mpp;
    int size=0;
    Router(int memoryLimit) {
        size=memoryLimit;

        
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        if(s.find({source,destination,timestamp})!=s.end()){
            return false;
        }
        if(q.size()>=size){
            s.erase(q.front());
            auto &vec = mpp[q.front()[1]];
            auto it=find(vec.begin(),vec.end(),q.front()[2]);
            vec.erase(it);
            q.pop();

        }
        q.push({source,destination,timestamp});
        s.insert({source,destination,timestamp});
        auto &vec = mpp[destination];
        auto it = lower_bound(vec.begin(), vec.end(), timestamp);
        vec.insert(it, timestamp);
        return true;
        
    }
    
    vector<int> forwardPacket() {
        if(q.size()>0){
            auto it=q.front();
            s.erase(it);
            auto &vec = mpp[q.front()[1]];
            auto it1 = find(vec.begin(),vec.end(),q.front()[2]);
            if(it1!=vec.end()){
                vec.erase(it1);

            }
            
            q.pop();
            return it;
            
        }
        return {};
        
    }
    
    int getCount(int destination, int startTime, int endTime) {
        auto &vec = mpp[destination];
        auto low = lower_bound(vec.begin(), vec.end(), startTime);
        auto high = upper_bound(vec.begin(), vec.end(), endTime);
        return high - low;
        
        
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */