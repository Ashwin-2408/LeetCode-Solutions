class Solution {
public:
    int compareVersion(string version1, string version2) {
        queue<int> q1,q2;
        string temp="";
        for(auto it: version1){
            if(it=='.'){
                q1.push(stoi(temp));
                temp="";
            }
            else{
                temp+=it;
            }

        }
        q1.push(stoi(temp));
        temp="";
        for(auto it: version2){
            if(it=='.'){
                q2.push(stoi(temp));
                temp="";
            }
            else{
                temp+=it;
            }

        }
        q2.push(stoi(temp));
        if(q1.size()!=q2.size()){
            if(q1.size()>q2.size()){
                for(int i=0;i<=q1.size()-q2.size();i++){
                    q2.push(0);
                }
            }
            else{
                for(int i=0;i<=q2.size()-q1.size();i++){
                    q1.push(0);
                }

            }
        }
        cout << q1 .size() << q2.size();
        while(!q1.empty() && !q2.empty()){
            if(q1.front()>q2.front()){
                return 1;
            }
            else if(q2.front()>q1.front()){
                return -1;
            }
            else{
                q1.pop();
                q2.pop();
            }
        }
        return 0;
    }
};