class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        map<int,int> mpp;
        for(auto it:  arr){
            mpp[it]++;
        }
        for(auto it: mpp){
            cout <<it.first << endl;
            if(it.first==0){
              
                if(it.second%2==1){
                    return false;
                }
            }
            else if(it.first%2==-1){
            
                return false;
            }
            else if(it.first<0 && mpp.count(it.first/2) && it.second <=mpp[(it.first/2)]){
                mpp[(it.first/2)]-=it.second;
                if(mpp[it.first/2]==0){
                    mpp.erase(it.first/2);
                }
                

            }
            else if(it.first>0 && mpp.count(it.first*2) && it.second <=mpp[(it.first*2)]){
                mpp[(it.first*2)]-=it.second;
                if(mpp[it.first*2]==0){
                    mpp.erase(it.first*2);
                    
                }
                
                
            }
            else{
             
                return false;
            }
            
        }
        return true;
        
    }
};