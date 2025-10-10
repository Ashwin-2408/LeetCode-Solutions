class Solution {
public:
    int twoEggDrop(int n) {
        return solve(n,1);
        
    }

    int solve(int n,int i){
        if(n<=0){
            return 0;
        }
        else{
            return 1+solve(n-i,i+1);
        }
    }
};