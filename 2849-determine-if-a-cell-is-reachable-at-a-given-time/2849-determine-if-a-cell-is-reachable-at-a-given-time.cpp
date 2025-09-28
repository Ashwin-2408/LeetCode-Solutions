class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if(sx==fx && sy==fy){
            if(t==1){
                return false;
            }
            return true;
        }

        int x_diff=abs(sx-fx);
        int y_diff=abs(sy-fy);

        int common=min(x_diff,y_diff);
        int remaining=x_diff-common +y_diff-common;
        int least_time=common+remaining;
        if(least_time<=t){
            return true;
        }
        return false;
    }
};