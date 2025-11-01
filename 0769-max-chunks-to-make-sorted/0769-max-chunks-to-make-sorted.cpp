class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int max_value=-1;
        int chunks=0;
        for(int i=0;i<arr.size();i++){
            max_value=max(max_value,arr[i]);
            if(i==max_value){
                chunks++;

            }
        }
        
        return chunks;
    }
};