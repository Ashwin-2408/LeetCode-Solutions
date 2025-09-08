class Solution {
public:
    bool nonzero(int i){
        string s = to_string(i);
        for(auto it: s){
            if(it=='0'){
                return false;
            }
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        if(n==2){
            return {1,1};
        }
        for(int i=1;i<n;i++){
            if(nonzero(i) && nonzero(n-i)){
                return {i,n-i};
            }

        }
        return {0,0};
        
    }
};