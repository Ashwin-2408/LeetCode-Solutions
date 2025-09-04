class Solution {
public:
    int findClosest(int x, int y, int z) {
        int dist_y=abs(y-z);
        int dist_x=abs(x-z);
        if(dist_y>dist_x){
            return 1;
        }
        else if(dist_y<dist_x){
            return 2;
        }
        return 0;
        
    }
};