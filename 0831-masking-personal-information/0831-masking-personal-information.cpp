class Solution {
public:
    string maskPII(string s) {
        bool is_number=false;
        for(int i=0;i<s.size();i++){
            if(isdigit(s[i])){
                is_number=true;
                break;
            }
        }
        if(is_number){
            stack<char> st;
            for(auto it :s){
                if(isdigit(it)){
                    st.push(it);
                }
            }

            string last_digits="";
            string front="";
            if(st.size()==10){
                front="***-***-";
            }
            else if(st.size()==11){
                front="+*-***-***-";

            }
            else if(st.size()==12){
                front="+**-***-***-";

            }
            else{
                front="+***-***-***-";
            }
            
            for(int i=0;i<4;i++){
                last_digits=st.top()+last_digits;
                st.pop();
            }
            return front+last_digits;

          
        }
        else{
           string ans="";
           bool rate=false;
           for(int i=0;i<s.size();i++){
            if(i==0){
                ans+=tolower(s[i]);
            }
            if(s[i]=='@'){
                ans=ans+"*****";
                ans+=tolower(s[i-1]);
                ans+="@";
                rate=true;
            }
            if(rate && isalpha(s[i])){
                ans+=tolower(s[i]);
            }
            if(rate && s[i]=='.'){
                ans+=s[i];
            }
            

           }
           return ans;
           

        }

        
    }
};