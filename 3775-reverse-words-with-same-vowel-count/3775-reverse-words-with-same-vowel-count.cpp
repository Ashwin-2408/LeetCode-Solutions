class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        s.push_back(' ');
        int n=s.size();
        string temp="";
        int vowels=0;
        int vowel_count=0;
        for(int i=0;i<n;i++){
            if(s[i]==' '){
                if(ans.size()==0){
                    vowels=vowel_count;
                    vowel_count=0;
                    ans+=temp;
                    temp.clear();
                    ans.push_back(' ');

                }
                else{
                    if(vowel_count==vowels){
                        reverse(temp.begin(),temp.end());
                        ans+=(temp);

                    }
                    else{
                        ans+=(temp);
                    }
                    temp.clear();
                    vowel_count=0;
                    ans.push_back(' ');


                }
            }
            else{
                temp.push_back(s[i]);
                if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                    vowel_count++;
                }

            }
            

        }
        string trimmed_ans=ans.substr(0,ans.size()-1);
        return trimmed_ans;


        
    }
};