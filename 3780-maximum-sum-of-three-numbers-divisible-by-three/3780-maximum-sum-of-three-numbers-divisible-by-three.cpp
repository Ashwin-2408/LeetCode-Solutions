class Solution {
public:
    int maximumSum(vector<int>& nums) {
        vector<int> remainder1,remainder2,remainder0;
        for(auto it: nums){
            if(it%3==0){
                remainder0.push_back(it);
            }
            else if(it%3==1){
                remainder1.push_back(it);
            }
            else{
                remainder2.push_back(it);
            }
        }
        int ans=0;
        sort(remainder0.begin(),remainder0.end());
        sort(remainder1.begin(),remainder1.end());
        sort(remainder2.begin(),remainder2.end());
        if(remainder0.size()>=3){
            int n=remainder0.size();
            ans=max(ans,remainder0[n-1]+remainder0[n-2]+remainder0[n-3]);
        }
        if(remainder1.size()>=3){
            int n=remainder1.size();
            ans=max(ans,remainder1[n-1]+remainder1[n-2]+remainder1[n-3]);
        }
        if(remainder2.size()>=3){
            int n=remainder2.size();
            ans=max(ans,remainder2[n-1]+remainder2[n-2]+remainder2[n-3]);
        }
        if(remainder1.size()>0 && remainder2.size()>0 && remainder0.size()>0){
            ans=max(ans,remainder1[remainder1.size()-1]+remainder2[remainder2.size()-1]+remainder0[remainder0.size()-1]);
        }
        return ans;
        
    }
};