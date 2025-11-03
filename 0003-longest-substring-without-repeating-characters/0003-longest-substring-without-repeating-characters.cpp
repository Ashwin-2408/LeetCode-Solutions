class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mpp;
        int i=0;
        int j=0;
        int result=0;
        while(j<s.size()){
            mpp[s[j]]++;
            while(i<j && mpp[s[j]]>1){
                mpp[s[i]]--;
                i++;
            }
            result=max(result,j-i+1);
            j++;

        }
        return result;
        
    }
};