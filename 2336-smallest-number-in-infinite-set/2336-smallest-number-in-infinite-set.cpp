class SmallestInfiniteSet {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    unordered_set<int> exist;

    int x;
   
    SmallestInfiniteSet() {
        x=1;
        
    }
    
    int popSmallest() {
        if(!pq.empty() && pq.top()<x){
            int val=pq.top();
            exist.erase(pq.top());
            pq.pop();
            return val;
        }
        else{
            int val=x;
            x++;
            return val;

        }
        
        
        
    }
    
    void addBack(int num) {
        if(num<x && exist.count(num)==0){
            pq.push(num);
            exist.insert(num);


        }
        
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */