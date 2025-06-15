class Solution {
public:
    string generateTag(string caption) {
        int size=1;
        string ans = "#";
        bool capitalize=false;
        bool begin=true;
        for(auto it : caption ){
            if(begin){
                if(isalpha(it)){
                    ans+=tolower(it);
                    begin=false;
                    size++;
                }
            }
            else{
            if(size>=100){
                break;
            }
            if(isalpha(it)){
                if(capitalize){
                    ans+=toupper(it);
                    capitalize=false;
                }
                else{
                    ans+=tolower(it);
                }
                size++;
            }
            else if(it==' '){
                capitalize=true;
            }
            }
        }
        return ans;
        
    }
};