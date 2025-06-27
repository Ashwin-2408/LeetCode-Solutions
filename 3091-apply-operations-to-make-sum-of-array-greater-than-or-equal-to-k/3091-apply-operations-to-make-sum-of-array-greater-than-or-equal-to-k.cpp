class Solution {
public:
    int minOperations(int k) {
        int min_count=INT_MAX;
        if(k==1){
            return 0;
        }

        for(int i=0;i<k;i++){
            int op_Count=0;
            int increase=i+1;
            int duplicates=(k/increase);
            min_count=min(min_count,i+duplicates);



        }
        if(min_count==INT_MAX){
            return 0;
        }
        else{
            return min_count;

        }
        
    }
};