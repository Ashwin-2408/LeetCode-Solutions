class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(auto it:tokens){
            if(it=="*" || it=="+" ||it=="-"||it=="/"){
                int x=s.top();
                s.pop();
                int y=s.top();
                s.pop();
                if(it=="*"){
                    s.push(x*y);
                }
                else if(it=="+"){
                    s.push(y+x);
                }
                else if(it=="-"){
                    s.push(y-x);
                }
                else{
                    s.push(y/x);
                }
            }
            else{
                s.push(stoi(it));
            }
        }
        return s.top();
        
    }
};