class Solution {
public:
    int maxSum(vector<int>& nums) {
        int max_elem=*max_element(nums.begin(),nums.end());
        if(max_elem<0){
            return max_elem;
        }
        unordered_set<int> s;
        for(auto it: nums){
            if(it>0){
                s.insert(it);
            }
        }
        int ans=0;
        for(auto it: s){
            ans+=it;
        }
        return ans;
        
    }
};