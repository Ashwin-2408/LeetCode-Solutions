class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<pair<string,int>> arr;
        for(int i=0;i<words.size();i++){
            string temp=words[i];
            sort(temp.begin(),temp.end());
            arr.push_back({temp,i});
        }
        sort(arr.begin(),arr.end());
        string curr=arr[0].first;
        vector<pair<int,string>> ans;
        ans.push_back({arr[0].second,words[arr[0].second]});
        for(int i=1;i<arr.size();i++){
            if(arr[i].first==curr){
                continue;
            }
            else{
                curr=arr[i].first;
                ans.push_back({arr[i].second,words[arr[i].second]});
            }
        }
        sort(ans.begin(),ans.end());
        vector<string> final_ans;
        for(auto it: ans){
            final_ans.push_back(it.second);
        }
        return final_ans;
    }
};