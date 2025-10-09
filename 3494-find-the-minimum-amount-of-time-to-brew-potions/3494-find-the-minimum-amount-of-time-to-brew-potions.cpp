class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n=mana.size();
        int m=skill.size();
        vector<vector<long long>> time (n,vector<long long>(m+1,0));
        for(int i=1;i<m+1;i++){
            time[0][i]=time[0][i-1]+mana[0]*skill[i-1];
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m+1;j++){
                time[i][j]=max(time[i-1][j],time[i][j-1])+mana[i]*skill[j-1];
            }
            for(int j=m-1;j>=0;j--){
                time[i][j]=time[i][j+1]-mana[i]*skill[j];
            }
        }
        return time[n-1][m];

    }
};