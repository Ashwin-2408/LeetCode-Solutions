class MyCalendarThree {
public:
    map<int,int> mpp;
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        mpp[startTime]++;
        mpp[endTime]--;
        int count=0;
        int max_overlap=INT_MIN;
        for(auto it: mpp){
            count+=it.second;
            max_overlap=max(count,max_overlap);

        }
        return max_overlap;
        
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */