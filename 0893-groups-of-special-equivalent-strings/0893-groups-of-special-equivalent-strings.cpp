class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        set<vector<int>> s;
        for(auto word:words){
            vector<int> temp(51,0);
            for(int i=0;i<word.size();i++){
                if(i%2==0){
                    temp[word[i]-'a']++;
                }
                else{
                    temp[word[i]-'a'+25]++;
                }
            }
            s.insert(temp);
        }
        return s.size();
        
    }
};