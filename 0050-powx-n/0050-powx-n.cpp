class Solution {
public:
    double myPow(double x, int n) {
        if(n==0){
            return 1;
        }
        double carry=1;
        bool negative=false;;
        if(n<0){
            negative=true;
        }
        long n1=abs((long)n);
        while(n1>0){
            if(n1%2==1){
                carry*=x;
            }
            x=x*x;
            n1=n1/2;


        
        }
        if(negative){
                return 1/(x*carry);
        }
        else{
            
                return x*carry;
            
        }
    }
};