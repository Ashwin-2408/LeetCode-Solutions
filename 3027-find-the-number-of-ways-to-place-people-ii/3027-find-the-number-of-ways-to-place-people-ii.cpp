class Solution {
public:
    static bool comparator(vector<int>&a,vector<int>&b){
        if(a[0]==b[0]){
            return b[1]<a[1];
        }
        else{
            return a[0]<b[0];
        }
    }
    int numberOfPairs(vector<vector<int>>& points) {
        int ans=0;
        int n=points.size();
        sort(points.begin(),points.end(),comparator);
        for(int i=0;i<points.size();i++){
            int prev_y=INT_MIN;
            for(int j=i+1;j<points.size();j++){
                if(points[j][1]<=points[i][1] && prev_y<points[j][1]){
                    ans++;
                    prev_y=points[j][1];
                    
                }
                
                
                
                
                
                
            }
        }
        return ans;

        
    }
};