class Solution {
public:
    bool hasSameDigits(string s) {
        int c=s[0]-'0';
        string temp="";
        while(s.size()!=2){
            for(int i=0;i<s.size()-1;i++){
                temp.push_back((((s[i]-'0')+(s[i+1]-'0'))%10)+'0');
            }
            s=temp;
            temp="";
            cout << s;




        }
        if(s[0]==s[1]){
            return true;
        }
        return false;
       
    }
};