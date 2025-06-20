class Solution {
public:
    int maxDistance(string s, int k) {
        int north=0;
        int south=0;
        int east=0;
        int west=0;
        int total=0;
        
        for(auto it: s){
            if(it=='N'){
                north++;
            }
            else if(it=='S'){
                south++;
            }
            else if(it=='E'){
                east++;
            }
            else{
                west++;
            }
            int x=min({east,west,k});
            int y=min({north,south,k-x});
            total=max(total,count(east,west,x)+count(north,south,y));
        }
        
        return total;

        
    }
    int count(int x,int y,int z){
        return abs(x-y) + 2*z;
    }
};