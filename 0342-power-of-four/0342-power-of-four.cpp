class Solution {
public:
    bool isPowerOfFour(int n) {
        int set_bits=0;
        bool even=true;
        while(n>0){
            if((n&1)==1){
                if(!even){
                    return false;
                }
                set_bits++;
                
            }
            even=!even;
            n=n>>1;
        }
        if(set_bits==1){
            return true;
        }
        return false;
        
    }
};