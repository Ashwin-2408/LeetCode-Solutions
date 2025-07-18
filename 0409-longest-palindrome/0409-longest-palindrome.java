class Solution {
    public int longestPalindrome(String s) {
        if(s.length()==1){
            return 1;    
        }
        Map<Character,Integer> mpp = new HashMap<>();

        for(char ch:s.toCharArray()){
            mpp.put(ch,mpp.getOrDefault(ch,0)+1);
        }
        int ans=0;
        boolean flag=false;
        for(Map.Entry<Character,Integer> entry : mpp.entrySet()){
            if(entry.getValue()%2!=0){
                flag=true;
                ans+=entry.getValue()-1;
            }
            else{
                ans+=entry.getValue();
            }
            

        }
        if(flag){
            ans+=1;
        }
        return ans;
        
    }
}