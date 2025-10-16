class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int,int> mpp;
        for(auto it: nums){
            mpp[((it%value)+value)%value];
        }
        int i=0;
        for(auto it: mpp){
            if(mpp.count(i%value)==0){
                return i;
            }
            mpp[i%value]--;
            i++;

        }
        return i;
        
    }
};