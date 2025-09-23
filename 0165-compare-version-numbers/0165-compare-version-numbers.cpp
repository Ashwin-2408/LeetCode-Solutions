class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i=0;
        int j=0;
        vector<string> v1,v2;
        string temp="";
        while(i<=version1.size()){
            if(i==version1.size() || version1[i]=='.'){
                v1.push_back(temp);
                temp.clear();
            }
            else{
                temp.push_back(version1[i]);
            }
            i++;
            

        }
        while(j<=version2.size()){
            if(j==version2.size() || version2[j]=='.'){
                v2.push_back(temp);
                temp.clear();
            }
            else{
                temp.push_back(version2[j]);
            }
            j++;
            

        }
        i=0;
        j=0;
        while(i<v1.size() && j<v2.size()){
            if(stoi(v1[i])>stoi(v2[j])){
                return 1;
            }
            else if(stoi(v1[i])<stoi(v2[j])){
                return -1;
            }
            else{
                i++;
                j++;
            }

        }
        while(i<v1.size()){
            if(stoi(v1[i])>0){
                return 1;
            }
            i++;
        }
        while(j<v2.size()){
            if(stoi(v2[j])>0){
                return -1;
            }
            j++;
        }
        return 0;
        
    }
};