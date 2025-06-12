class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> visited(nums.size(),false);
        set<vector<int>> final_ans;
        vector<int> ans;
        backtrack(nums,ans,final_ans,visited);
        vector<vector<int>> result(final_ans.begin(),final_ans.end());
        return result;

        
    }
    void backtrack(vector<int>& nums,vector<int>& ans,set<vector<int>>& final_ans,vector<bool> & visited){
        if(ans.size()==nums.size()){
            final_ans.insert(ans);
            return;
        }
        
        for(int i=0;i<nums.size();i++){
            if(visited[i]==false){
                visited[i]=true;
                ans.push_back(nums[i]);
                backtrack(nums,ans,final_ans,visited);
                visited[i]=false;
                ans.pop_back();
            }
            
        }
    }
};