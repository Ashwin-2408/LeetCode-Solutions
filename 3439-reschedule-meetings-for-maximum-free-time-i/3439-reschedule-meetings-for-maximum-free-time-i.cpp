class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int> gaps;
        if(startTime[0]!=0){
            gaps.push_back(startTime[0]);

        }
        
        for(int i=1;i<startTime.size();i++){
           
                gaps.push_back(startTime[i]-endTime[i-1]);
          

        }
        if(endTime[endTime.size()-1]<eventTime){
            gaps.push_back(eventTime-endTime[endTime.size()-1]);
        }
        int i=0;
        int j=0;
        int ans=0;
        int gap=0;
        if(gaps.size()<=k+1){
            int val=accumulate(gaps.begin(),gaps.end(),0);
            return val;
        }
       
        while(j<gaps.size()){
            gap+=gaps[j];
            cout << gaps[j];
            if(j-i+1==(k+1)){
                ans=max(ans,gap);
                gap-=gaps[i];
                i++;
            }
            j++;
            
        }
        return ans;
        
        
    }
};