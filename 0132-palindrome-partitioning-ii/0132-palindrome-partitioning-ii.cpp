class Solution {
public:
    vector<int> dp;
    bool is_palindrome(string &s,int i,int j){
        

        
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int minCut(string s) {
        int n=s.size();
        dp.resize(n,-1);
        return min_partitions(s,0,s.size()-1);
        
    }

    int min_partitions(string s,int i,int j){
        if(i>=j || is_palindrome(s,i,j)){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int min_partition=INT_MAX;
        for(int k=i;k<j;k++){
            if(is_palindrome(s,i,k)){
            int temp = 1 +min_partitions(s,k+1,j);
            min_partition=min(min_partition,temp);
            }
            
            
        }
        return dp[i]=min_partition;
    }
};