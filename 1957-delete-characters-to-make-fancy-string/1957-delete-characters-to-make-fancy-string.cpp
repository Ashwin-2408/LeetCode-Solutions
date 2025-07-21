class Solution {
public:
    string makeFancyString(string s) {
        int i=0;
        int count=0;
        string ans="";
        char curr=' ';
       
        while(i<s.size()){
            if(curr==' '){
                ans+=s[i];
                count=1;
                curr=s[i];
                
            }
            else{
                if(s[i]==curr && count <2){
                    ans+=s[i];
                    count++;
                }
                else if(s[i]!=curr){
                    ans+=s[i];
                    count=1;
                    curr=s[i];
                }
            }
            i++;
            
           
        }
        
        return ans;
        
    }
};