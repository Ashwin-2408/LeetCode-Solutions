class Solution {
public:
    int edgeScore(vector<int>& edges) {
        vector<long long> edge_score(edges.size(),0);
        for(int i=0;i<edges.size();i++){
            edge_score[edges[i]]+=i;
        }
        int max_index=-1;
        long long max_val=INT_MIN;
        for(int i=0;i<edges.size();i++){
            if(edge_score[i]>max_val){
                max_index=i;
                max_val=edge_score[i];
            }

        }
        return max_index;


        
    }
};