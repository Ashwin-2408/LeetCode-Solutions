class Solution {
public:
    static bool comparator(pair<int,int>&a,pair<int,int>&b){
        return a.second <b.second;
    }
    
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int,int>> arr;
        for(int i=0;i<nums.size();i++){
            arr.push_back({nums[i],i});
        }
        sort(arr.begin(),arr.end());
        vector<pair<int,int>> ans;
        for(int i=arr.size()-1;i>=arr.size()-k && i>=0;i--){
            ans.push_back({arr[i].first,arr[i].second});
        }
        sort(ans.begin(),ans.end(),comparator);
        vector<int> final_ans;
        for(auto it: ans){
            final_ans.push_back(it.first);
        }
        return final_ans;
        
    }
};