class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> curr;
        curr.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(curr.size()==3){
                ans.push_back(curr);
                curr.clear();
                curr.push_back(nums[i]);
            }
            else if(curr.size()==1){
                if(abs(curr[0]-nums[i])>k){
                    return {};

                }
                else{
                    curr.push_back(nums[i]);
                }
            }
            else if(curr.size()==2){
                if(abs(curr[0]-nums[i])>k){
                    return {};

                }
                else{
                    curr.push_back(nums[i]);
                }

            }

        }
        ans.push_back(curr);
        return ans;
        
    }
};