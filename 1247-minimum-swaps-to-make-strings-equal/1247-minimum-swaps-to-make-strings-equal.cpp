class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int x_count=0;
        int y_count=0;
        for(auto it: s1){
            if(it=='x'){
                x_count++;
            }
            else{
                y_count++;
            }
        }
        for(auto it: s2){
            if(it=='x'){
                x_count++;
            }
            else{
                y_count++;
            }
        }
        if(x_count%2==1 || y_count%2==1){
            return -1;
        }
        int count_x_mismatch=0;
        int count_y_mismatch=0;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                if(s1[i]=='x'){
                    count_x_mismatch++;
                }
                else{
                    count_y_mismatch++;
                }
            }
        }
        cout << count_x_mismatch << count_y_mismatch;
        int ans= (count_x_mismatch/2) + (count_y_mismatch/2) + ((count_x_mismatch%2==1) ? 2 :0);
        return ans;

    }
};