class Solution {
public:
    int nextBeautifulNumber(int n) {
        for(int i=n+1;i<=1e6;i++){
            if(valid(to_string(i))){
                return i;
            }
        }
        return -1;
        
    }
    bool valid(string n){
        vector<int> count(10,0);
        for(auto it: n){
            if(it=='0'){
                return false;
            }
            else{
                count[it-'0']++;
            }
        }
        for(int i=1;i<10;i++){
            if(count[i]>0 && count[i]!=i){
                return false;
            }
        }
        return true;

    }
};