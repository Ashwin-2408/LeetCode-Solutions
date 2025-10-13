class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        map<long long,int> mpp;
        for(auto it: changed){
            mpp[it]++;
        }
        if(mpp.count(0)){
            if(mpp[0]%2==1){
                return {};
            }
        }
     
        
        vector<int> ans;
        
            
        for(auto it: mpp){
            if(it.first==0){
                for(int i=0;i<mpp[0]/2;i++){
                    ans.push_back(0);
                }

            }
            else if(mpp.count(it.first*2) && it.second <=mpp[it.first*2]){
                
                mpp[(it.first*2)]-=it.second;
                if(mpp[(it.first*2)]==0){
                    mpp.erase((it.first*2));
                }
                for(int i=0;i<it.second;i++){
                    ans.push_back(it.first);
                }

            }
            else{
                return {};
            }
        }
        return ans;
        
    }
};