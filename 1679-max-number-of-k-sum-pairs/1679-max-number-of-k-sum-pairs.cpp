class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<int,int> mpp;
        for(auto it:nums){
            mpp[it]++;
        }
        int ans=0;
        for(auto it: mpp){
            if(mpp.find(k-it.first)!=mpp.end()){
                if(it.first==k-it.first){
                    ans+=mpp[it.first]/2;
                    mpp[it.first]=0;
                }
                else{
                ans+=min(mpp[it.first],mpp[k-it.first]);
                mpp[it.first]=0;
                mpp[k-it.first]=0;
                }
            
            }
        }
        return ans;

        
    }
};