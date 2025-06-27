class Solution {

public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        const int MOD = 1e9 + 7;

        hFences.push_back(m);
        hFences.push_back(1);

        vFences.push_back(n);
        vFences.push_back(1);
        vector<int> h_diff;
        vector<int> v_diff;
        for(int i=0;i<hFences.size();i++){
            for(int j=i+1;j<hFences.size();j++){
                h_diff.push_back(abs(hFences[i]-hFences[j]));

            }
        }
        for(int i=0;i<vFences.size();i++){
            for(int j=i+1;j<vFences.size();j++){
                v_diff.push_back(abs(vFences[i]-vFences[j]));

            }
        }
        sort(v_diff.begin(),v_diff.end());
        sort(h_diff.begin(),h_diff.end());
        int i=h_diff.size()-1;
        int j=v_diff.size()-1;
        while(i>=0 && j>=0){
            if(h_diff[i]==v_diff[j]){
               return ((1LL * h_diff[i] *h_diff[i] ) % MOD);
            }
            else if(h_diff[i]>v_diff[j]){
                i--;
            }
            else{
                j--;
            }
        }
        return -1;
        
    }
};