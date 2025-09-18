class CustomStack {
public:
    vector<int> arr;
    int top;
    int cap=0;
    CustomStack(int maxSize) {
        arr.resize(maxSize);
        top=-1;
        cap=maxSize;
     
        
    }
    
    void push(int x) {
        if(top+1<cap){
            top++;
            arr[top]=x;
        }
        
    }
    
    int pop() {
        if(top>=0){
            return arr[top--];
            
        }
        return -1;
        
    }
    
    void increment(int k, int val) {
        for(int i=0;i<min(k,top+1);i++){
            arr[i]+=val;
        }
        
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */