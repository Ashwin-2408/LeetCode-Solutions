class Solution {
public:
    int longestValidParentheses(string s) {
        int left=0;
        int right=0;
        int ans=0;
        for(auto it: s){
            if(it=='('){
                left++;
            }
            else{
                right++;
            }
            if(left==right){
                ans=max(ans,left*right);
            }
            if(right>left){
                right=0;
                left=0;
            }
        }
        left=0;
        right=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='('){
                left++;
            }
            else{
                right++;
            }
            if(left==right){
                ans=max(ans,2*right);
            }
            if(right<left){
                right=0;
                left=0;
            }

        }
        return ans;
        
    }
};