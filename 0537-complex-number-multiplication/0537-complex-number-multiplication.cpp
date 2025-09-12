class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        string real1="";
        string imaginary1="";
        bool positive_imag1=true;
        bool positive_real1=true;
        
        int i=0;
        if(num1[i]=='-'){
            positive_real1=false;
            i++;
        }
        while(i<num1.size()){
            if(num1[i]=='+' || num1[i]=='-'){
                break;
            }
            else{
                real1.push_back(num1[i]);
            }
            i++;
        }

        while(i<num1.size()){
            if(num1[i]=='-'){
                positive_imag1=false;
            }
            else if(num1[i]=='+'){
                continue;
            }
            else{
                imaginary1.push_back(num1[i]);
            
            }
            i++;

        }
        string real2="";
        string imaginary2="";
        bool positive_imag2=true;
        bool positive_real2=true;

        
        i=0;
        if(num2[i]=='-'){
            positive_real2=false;
            i++;
        }
        while(i<num2.size()){
            if(num2[i]=='+' || num2[i]=='-'){
                break;
            }
            else{
                real2.push_back(num2[i]);
            }
            i++;
        }

        while(i<num2.size()){
            if(num2[i]=='-'){
                positive_imag2=false;
            }
            else if(num2[i]=='+'){
                continue;
            }
            else{
                imaginary2.push_back(num2[i]);
            
            }
            i++;

        }
        int real_1=stoi(real1);
        int imaginary_1=stoi(imaginary1);
        int real_2=stoi(real2);
        int imaginary_2=stoi(imaginary2);
        
        if(positive_imag1==false){
            imaginary_1=-imaginary_1;
        }
         if(positive_imag2==false){
            imaginary_2=-imaginary_2;
        }
        if(positive_real1==false){
            real_1=-real_1;
        }
        if(positive_real2==false){
            real_2=-real_2;
        }
        
        int real_part=(real_1*real_2)-(imaginary_1*imaginary_2);
        int imag_part=(real_1*imaginary_2)+(real_2*imaginary_1);
        string ans="";
        if(real_part<0){
            ans.push_back('-');

        }
        ans+=to_string(abs(real_part));
        ans.push_back('+');
        if(imag_part<0){
            ans.push_back('-');
        }
        
        ans+=to_string(abs(imag_part));
        ans.push_back('i');
        return ans;

        
    }
};