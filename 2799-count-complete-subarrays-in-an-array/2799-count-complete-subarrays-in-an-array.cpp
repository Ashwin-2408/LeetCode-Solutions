class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        set<int> elements;
        for(auto it: nums){
            elements.insert(it);
        }
        int ans=0;
        for(int i=0;i<nums.size();i++){
            set<int> element;
            for(int j=i;j<nums.size();j++){
                element.insert(nums[j]);
                if(elements.size()==element.size()){
                    ans++;
                }
                if(elements.size()<element.size()){
                    break;
                }

            }
        }
        return ans;
        
    }
};