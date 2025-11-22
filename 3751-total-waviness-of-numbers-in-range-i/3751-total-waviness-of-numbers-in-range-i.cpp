class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int sum=0;
        for(int i=num1;i<=num2;i++){
            sum+=wave(i);

        }
        return sum;
        
    }
    int wave(int n){
        string num =to_string(n);
        if(num.size()<=2){
            return 0;
        }
        int wavy=0;
        for(int i=1;i<num.size()-1;i++){
            if(num[i]<num[i-1] && num[i]<num[i+1]){
                wavy++;
            }
            else if(num[i]>num[i-1] && num[i]>num[i+1]){
                wavy++;
            }
        }
        return  wavy;
    }
};