class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        
        for(int i=0;i<asteroids.size();i++){
            bool destroyed=false;
            while(!s.empty() && s.top()*asteroids[i]<0){
                if(asteroids[i]>0 && s.top()<0){
                    break;
                }
               
                if(abs(s.top())<abs(asteroids[i])){
                    s.pop();
                }
                else if(abs(s.top())==abs(asteroids[i])){
                    s.pop();
                    destroyed=true;
                    break;
                }
                else{
                    destroyed=true;
                    break;
                }
            }
            if(!destroyed){
                s.push(asteroids[i]);
            }

           
        }
        vector<int> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};