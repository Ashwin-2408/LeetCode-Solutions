class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> freq;
        int total=0;
        int i=0;
        int j=0;
        while(j<fruits.size()){
            freq[fruits[j]]++;
            
            if(freq.size()<=2){
                total=max(total,j-i+1);
            }
            else{
                while(freq.size()>2){
                    freq[fruits[i]]--;
                    if(freq[fruits[i]]==0){
                        freq.erase(fruits[i]);

                    }
                    i++;
                }
            }
            j++;
        }
        return total;
        
    }
};