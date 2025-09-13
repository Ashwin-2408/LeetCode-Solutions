class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {
        unordered_map<int,int> mpp;
        int i=0;
        int j=0;
        int n=arrivals.size();
        vector<bool> discarded(n,false);
        int discards=0;
        while(j<n){
            
            if(j-i+1>w ){
                if(discarded[i]==true){
                    i++;
                    continue;
                }
                if(--mpp[arrivals[i]]==0){
                    mpp.erase(arrivals[i]);
                }
                i++;
            }
            if(mpp[arrivals[j]]==m){
                discards++;
                discarded[j]==true;
               
               
            }
            else{
            
          
             mpp[arrivals[j]]++;
            }
              
            j++;
            
        }
        return discards;

        
    }
};