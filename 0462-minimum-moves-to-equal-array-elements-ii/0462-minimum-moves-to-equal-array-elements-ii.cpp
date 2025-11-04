class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int mid=n/2;
        int moves=INT_MAX;
        if(n%2==1){
            int max_moves=0;
            for(int i=0;i<nums.size();i++){
                max_moves+=abs(nums[i]-nums[mid]);

            }
            moves=min(max_moves,moves);
        }
        else{
            int max_moves=0;
             for(int i=0;i<nums.size();i++){
                max_moves+=abs(nums[i]-nums[mid]);

            }
            moves=min(moves,max_moves);
            max_moves=0;
             for(int i=0;i<nums.size();i++){
                max_moves+=abs(nums[i]-nums[mid-1]);

            }
            moves=min(moves,max_moves);
            
        }
        return moves;
        
    }
};