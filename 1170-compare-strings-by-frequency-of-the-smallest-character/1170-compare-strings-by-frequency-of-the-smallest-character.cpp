class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        int maximum=0;
        vector<int> ans;
        map<int,int> frequency;
        for(auto it:words){
            char c=it[0];
            for(int i=0;i<it.size();i++){
                if(it[i]<c){
                    c=it[i];
                }
            }
            int freq=count(it.begin(),it.end(),c);
            maximum=max(maximum,freq);
            frequency[freq]++;
        }
        for(auto it:queries){
            char c=it[0];
            for(int i=0;i<it.size();i++){
                if(it[i]<c){
                    c=it[i];
                }
            }
            int freq=count(it.begin(),it.end(),c);
            int temp=0;
            for(int i=freq+1;i<=maximum;i++){
                if(frequency.find(i)!=frequency.end()){
                temp+=frequency[i];
                }

            }
            ans.push_back(temp);

        }
        for(auto it: frequency){
            cout << it.first << " : " << it.second << endl;
        }
        return ans;
        
    }
};