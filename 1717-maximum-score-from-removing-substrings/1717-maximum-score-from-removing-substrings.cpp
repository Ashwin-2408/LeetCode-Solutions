class Solution {
public:
    int maximumGain(string s, int x, int y) {
        stack<char> S;
        int ans=0;
        for(auto it: s){
            if(S.empty()){
                S.push(it);
                continue;
            }
            if(it!='a' && it!='b'){
                S.push(it);
            }
            else{
                if(x>y){
                    if(S.top()=='a' && it=='b'){
                        S.pop();
                        ans+=x;
                    }
                    else{
                        S.push(it);
                    }
                }
                else{
                    if(S.top()=='b' && it=='a'){
                        S.pop();
                        ans+=y;
                    }
                    else{
                        S.push(it);
                    }

                }
            }
        }
        stack<int> temp;
        while(!S.empty()){
            temp.push(S.top());
            S.pop();
        }
        while(!temp.empty()){
            if(S.empty()){
                S.push(temp.top());
                temp.pop();
            }
            else{
                if(temp.top()!='a' && temp.top()!='b'){
                    S.push(temp.top());
                    temp.pop();
                }
                else{
                     if(x<y){
                    if(S.top()=='a' && temp.top()=='b'){
                        S.pop();
                        temp.pop();
                        ans+=x;
                    }
                    else{
                        S.push(temp.top());
                        temp.pop();
                    }
                }
                else{
                    if(S.top()=='b' && temp.top()=='a'){
                        S.pop();
                        ans+=y;
                        temp.pop();
                    }
                    else{
                        S.push(temp.top());
                        temp.pop();
                    }

                }
                    

                }
            }
            
        }
        return ans;

        
    }
};