class Solution {
public:
    int minPartitions(string n) {
        char  maximum=n[0];
        for(auto it: n){
            maximum=max(maximum,it);
        }
        return maximum-'0';
        
    }
};