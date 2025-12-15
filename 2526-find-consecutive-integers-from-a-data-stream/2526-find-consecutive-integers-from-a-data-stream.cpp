class DataStream {
public:
    queue<int> q;
    int max_size;
    DataStream(int value, int k) {
        q.push(value);
        max_size=k;
        
    }
    
    bool consec(int num) {
        if(q.front()!=num){
            while(!q.empty()){
                q.pop();
            }
            q.push(num);
            return false;
        }
        else{
            if(q.size()==max_size){
                q.pop();
                q.push(num);
                return true;
            }
            else{
                q.push(num);
                return false;
            }
        }

        
        
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */