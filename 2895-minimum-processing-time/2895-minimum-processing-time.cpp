class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(tasks.begin(),tasks.end());
        sort(processorTime.begin(),processorTime.end(),greater<int>());
        int j=0;
        int min_process_time=0;
        for(int i=3;i<tasks.size();i+=4){
            min_process_time=max(min_process_time,processorTime[j]+tasks[i]);
            j++;

        }
        return min_process_time;
    }
};