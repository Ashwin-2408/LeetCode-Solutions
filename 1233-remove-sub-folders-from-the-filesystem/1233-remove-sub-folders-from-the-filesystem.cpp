class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        vector<string> ans;
        ans.push_back(folder[0]);
        for(int i=1;i<folder.size();i++){
            string last_folder=ans.back();
            last_folder+='/';
            if(folder[i].compare(0,last_folder.size(),last_folder)!=0){
                ans.push_back(folder[i]);
            }
            

        }
        return ans;
        
    }
};