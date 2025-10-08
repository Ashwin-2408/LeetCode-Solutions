class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int> ans;
        for(auto it: spells){
            long long needed=ceil((float)success/it);
       
            int index=binary_search(potions,0,potions.size(),needed);
            
            if(index==potions.size()){
                ans.push_back(0);
            }
            else{
                ans.push_back(potions.size()-index);

            }

           


        }
        return ans;
    }
    int binary_search(vector<int>& potions,int l,int r,long long target){
        while(l<r){
            int mid=(l+r)/2;
            if(potions[mid]>=target){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        return r;
    }
};