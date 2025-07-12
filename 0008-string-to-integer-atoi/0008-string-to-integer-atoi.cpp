class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        while(i<s.size() && s[i]==' '){
            i++;
        }
        int sign=1;
        if(i<s.size() && (s[i]=='-' || s[i]=='+')){
            if(s[i]=='-'){
            sign=-1;
            }
            i++;
        }
        long long ans=0;
        while(i<s.size()){
            char digit=' ';
            
            if(isdigit(s[i])){
                digit=(s[i]-'0');
            }
            else{
                break;
            }
            if((INT_MAX-digit)/10 <ans){
                if(sign==1){
                    return INT_MAX;
                }
                else{
                    return INT_MIN;
                }
            }
            else{
                ans=ans*10 + digit;
            }
            
            i++;
            

        }
        if(sign==-1){
            return -ans;
        }
        return ans;
        
    }
};