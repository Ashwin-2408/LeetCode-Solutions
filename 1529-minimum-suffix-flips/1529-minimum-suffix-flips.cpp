class Solution {
public:
    int minFlips(string target) {
        int ans=0;
        if(count(target.begin(),target.end(),'0')==target.size()){
            return 0;
        }
        for(int i=target.size()-1;i>=0;i--){
            if(target[i]=='0'){
                ans++;
                while(i>=0 && target[i]=='0'){
                    i--;
                }
                i++;
            }
            else{
                ans++;
                while(i>=0 && target[i]=='1'){
                    i--;
                }
                i++;

            }
            

        }
        return ans;
        
    }
};