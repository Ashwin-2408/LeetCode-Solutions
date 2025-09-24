class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        

        string before_decimal;

        if((numerator<0 && denominator>0) || (numerator >0 && denominator<0)){
            before_decimal.push_back('-');
        }
        long long n=abs((long long)numerator);
        long long d=abs((long long)denominator);

        before_decimal+=(to_string(n/d));

        long long remainder =n%d;
        if(remainder==0){
            return before_decimal;
        }
        string  after_decimal;
        unordered_map<long long,int> mpp;
        while(remainder!=0){
            if(mpp.count(remainder)){
                after_decimal.insert(mpp[remainder],"(");
                after_decimal.push_back(')');
                break;
            }
            mpp[remainder]=after_decimal.size();
            remainder*=10;
            after_decimal+=(to_string(remainder/d));
            remainder%=d;

        }
        return before_decimal + "." + after_decimal;
    }
};