class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {

        int area1=(ax2-ax1)*(ay2-ay1);
        int area2=(bx2-bx1)*(by2-by1);
        int smallx=0;
        int smally=0;

        if(bx1>=ax1 && bx2>=ax2 && ax2>=bx1){
            smallx=ax2-bx1;

        }
        else if(bx1>=ax1 && bx2<=ax2){
            smallx=bx2-bx1;
        }
        else if(bx1<=ax1 && bx2<=ax2 && ax1<=bx2){
            smallx=bx2-ax1;
        }
        else if(ax1>=bx1 && ax2<=bx2){
            smallx=ax2-ax1;
        }
        if(by1>=ay1 && by2>=ay2 && ay2>=by1){
            smally=ay2-by1;

        }
        else if(by1>=ay1 && by2<=ay2){
            smally=by2-by1;
        }
        else if(by1<=ay1 && by2<=ay2 && ay1<=by2){
            smally=by2-ay1;
        }
        else if(ay1>=by1 && ay2<=by2){
            smally=ay2-ay1;
        }
        int common_area=smallx*smally;
        return area1+area2-common_area;
        
    }
};