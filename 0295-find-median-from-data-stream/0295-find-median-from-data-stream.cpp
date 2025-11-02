class MedianFinder {
public:
    priority_queue<int> maxheap;
    priority_queue<int,vector<int>,greater<int>> minheap;
    MedianFinder() {
        
        
    }
    
    void addNum(int num) {
        if(maxheap.empty()|| num<=maxheap.top()){
            maxheap.push(num);

        }
        else{
            minheap.push(num);
        }
        if(minheap.size()>maxheap.size()){
            maxheap.push(minheap.top());
            minheap.pop();
        }
        else if(maxheap.size()>minheap.size()+1){
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        return ;
        
    }
    
    double findMedian() {
        if(minheap.size()==maxheap.size()){
            return (double)(minheap.top()+maxheap.top())/2;
        }
        else{
            return (double)(maxheap.top());
        }
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */