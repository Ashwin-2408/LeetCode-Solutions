class Solution {
public:
    int longestBeautifulSubstring(string word) {
        char curr='b';
        int max_length=0;
        int curr_length=0;
        for(int i=0;i<word.size();i++){
            if(word[i]=='a'){
                if(curr=='b' || curr=='a'){
                    curr_length++;
                    curr='a';
                }
                else{
                    curr_length=1;
                    curr='a';
                }
            }
            else if(word[i]=='e'){
                if(curr=='e' || curr=='a'){
                    curr_length++;
                    curr='e';
                }
                else{
                    curr='b';
                    curr_length=0;
                    

                }
            }
            else if(word[i]=='i'){
                if(curr=='i' || curr=='e'){
                    curr_length++;
                    curr='i';
                }
                else{
                    curr='b';
                    curr_length=0;
                    

                }
                

            }
            else if(word[i]=='o'){
                if(curr=='i' || curr=='o'){
                    curr_length++;
                    curr='o';
                }
                else{
                    curr='b';
                    curr_length=0;
                    

                }
                

            }
            else{
                if(curr=='o'||curr=='u'){
                    curr_length++;
                    max_length=max(max_length,curr_length);
                    curr='u';
                }
                else{
                    curr='b';
                    curr_length=0;

                }
            }

        }
        return max_length;
        
    }
};