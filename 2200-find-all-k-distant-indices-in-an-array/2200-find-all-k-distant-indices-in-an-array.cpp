class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> k_index;
        vector<bool> visited(nums.size(),false);
        for(int i=0;i<nums.size();i++){
            if(nums[i]==key){
                for(int j=k;j>=0;j--){
                    int left=i-j;
                   
                    if(left>=0 && left <nums.size() && visited[left]!=true) {
                        k_index.push_back(left);
                        visited[left]=true;
                    } 
                }
                if(visited[i]!=true){
                    k_index.push_back(i);
                    visited[i]=true;
                }
                for(int j=1;j<=k;j++){
                    int right=i+j;
                    if(right>=0 && right <nums.size() && visited[right]!=true) {
                        k_index.push_back(right);
                        visited[right]=true;
                    }
                }

                
            }
        }
        return k_index;
        
        
    }
};