class Solution {
public:
    int decode_ways(string s,int i){
        if(s.size()==i){
            return 1;
        }
        string single_letter=s.substr(i,1);
        string double_letter="";
        int ways=0;
        if(s.size()-i>=2){
            double_letter=s.substr(i,2);
        
        }
        if(stoi(single_letter)>0 && stoi(single_letter)<=9){
            if(double_letter!=""&& double_letter[0]!='0'  && stoi(double_letter)>0 && stoi(double_letter)<=26){
                ways+=decode_ways(s,i+1)+decode_ways(s,i+2);
            }
            else{
                ways+=decode_ways(s,i+1);
            }

        }
        else{
            if(double_letter!="" && double_letter[0]!='0' && stoi(double_letter)>0 && stoi(double_letter)<=26){
                ways+=decode_ways(s,i+2);
            }
            
            
        }
        return ways;
    }
    int numDecodings(string s) {
        if(s[0]=='0'){
            return 0;
        }
        int ans=decode_ways(s,0);
        return ans;
        
    }
};