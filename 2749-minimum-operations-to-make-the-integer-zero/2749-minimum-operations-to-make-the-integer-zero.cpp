class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
       for(int i=0;i<61;i++){
        long long val=(long long)num1-((long long)i*num2);
        int set_bits=0;
        if(val<0){
            continue;
        }
        long long temp=val;
        while(val>0){
            
            if((val & 1) ==1){
                set_bits++;
                
            }
            val=val>>1;
        }
        if(set_bits<=i && i<=temp){
            return i;
        }

       }
       return -1;

        
    }
};