class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        vector<int> ans(n,0);
        if(x>y){
            swap(x,y);
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                int temp=0;
                if(i==j){
                    continue;
                }
                else{
                    int direct=j-i;
                    int X=abs(i-x)+abs(j-y)+1;
                    int Y=abs(i-y)+abs(j-x)+1;
                    temp=min({direct,X,Y});
                   
                    ans[temp-1]+=2;
                }
            }
        }
        return ans;
        
    }
};