class Solution {
public:
    int getLeastFrequentDigit(int n) {
        vector<int> track(10);
        int least=INT_MAX;
        while(n>0){
            track[n%10]++;
            least=min(least,track[n%10]);
            n=n/10;
            
        }
        for(int i=0;i<10;i++){
            if(least==track[i]){
                return i;
            }
        }
        return 0;
    }
};