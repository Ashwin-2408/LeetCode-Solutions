class Solution {
public:
    bool is_palindrome(string & s,int i,int j){
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
        
    }
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        vector<vector<string>> ans;

        find_partitions(s,0,s.size()-1,temp,ans);
        return ans;

        
    }
    void find_partitions(string s,int i,int j,vector<string> temp,vector<vector<string>>& ans){
        if(i>j){
            
            ans.push_back(temp);
            return;
        }
        for(int k=i;k<=j;k++){
            if(is_palindrome(s,i,k)){
                temp.push_back(s.substr(i,k-i+1));
                find_partitions(s,k+1,j,temp,ans);
                temp.pop_back();
            }
            
        }
    }
};