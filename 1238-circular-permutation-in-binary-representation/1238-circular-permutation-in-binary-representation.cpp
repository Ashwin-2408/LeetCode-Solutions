class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int> arr;
        int index=0;
        for(int i=0;i<(1<<n);i++){
            int val=(i^(i>>1));
            if(val==start){
                index=i;
            }
            arr.push_back(i^(i>>1));
        }
        vector<int> ans;
        for(int i=index;i<arr.size();i++){
            ans.push_back(arr[i]);
        }
        for(int i=0;i<index;i++){
            ans.push_back(arr[i]);
        }
        return ans;

        
    }
};