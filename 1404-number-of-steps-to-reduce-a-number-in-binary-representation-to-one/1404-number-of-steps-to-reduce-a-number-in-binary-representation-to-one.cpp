class Solution {
public:
    int numSteps(string s) {
        int steps=0;
        while(s.size()>1){
            if(s[s.size()-1]=='1'){
    
                s[s.size()-1]='0';
                int i=s.size()-2;
                bool reach_end=true;
                while(i>=0){
                    if(s[i]=='1'){
                        s[i]='0';
                    }
                    else{
                        s[i]='1';
                        reach_end=false;
                        break;

                    }
                    i--;
                }
                if(reach_end){
                    s='1'+s;
                }
                steps++;

            }
            else{
                
                s=s.substr(0,s.size()-1);
                steps++;
            }
            cout << s << endl;
            


        }
        cout <<s;
        return steps;
        
        
    }
};