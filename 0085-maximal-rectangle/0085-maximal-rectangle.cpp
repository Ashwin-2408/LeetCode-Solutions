class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans=0;
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> arr(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='0'){
                    arr[j]=0;
                }
                else{
                    arr[j]+=matrix[i][j]-'0';
                }
            }
            ans=max(ans,largestRectangleArea(arr));

        }
        return ans;

        
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nse(heights.size(),0);
        vector<int> pse(heights.size(),0);
        stack<pair<int,int>> s;
        
        for(int i=0;i<heights.size();i++){
            while(!s.empty() && heights[i]<=s.top().first){
                s.pop();

            }
            if(s.empty()){
                pse[i]=-1;
            }
            else{
                pse[i]=s.top().second;
            }
            s.push({heights[i],i});


        }
        while(!s.empty()){
            s.pop();
        }
        
        for(int i=heights.size()-1;i>=0;i--){
            while(!s.empty() && heights[i]<=s.top().first){
                s.pop();

            }
            if(s.empty()){
                nse[i]=heights.size();
            }
            else{
                nse[i]=s.top().second;
            }
            s.push({heights[i],i});


        }
        int maximum_ans=0;
        for(int i=0;i<heights.size();i++){
            maximum_ans=max(maximum_ans,heights[i]*(nse[i]-pse[i]-1));
        }
        return maximum_ans;
    }
};