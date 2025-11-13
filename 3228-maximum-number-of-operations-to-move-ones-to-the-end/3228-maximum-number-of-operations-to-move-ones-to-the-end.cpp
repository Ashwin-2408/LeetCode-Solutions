class Solution {
public:
    int maxOperations(string s) {
        vector<int> groups(s.size(),0);
        int group=0;
        int ans=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='0'){
                group++;
                while(i>=0 && s[i]=='0'){
                    groups[i]=group;
                    i--;

                }
                i++;
            }
            else{
                if(i==s.size()-1){
                    groups[i]=0;
                }
                else{
                    cout <<'e';
                    groups[i]=groups[i+1];
                    ans+=groups[i+1];
                }

            }

        }
        return ans;
        
    }
};