class DataStream {
public:
    queue<int> q;
    int max_size;
    int check;
    DataStream(int value, int k) {
        check=value;
        max_size=k;
        
    }
    
    bool consec(int num) {
        if(check!=num){
            while(!q.empty()){
                q.pop();
            }
            return false;
        }
        else{
            q.push(num);
            if(q.size()>=max_size){
                return true;
            }
            else{
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