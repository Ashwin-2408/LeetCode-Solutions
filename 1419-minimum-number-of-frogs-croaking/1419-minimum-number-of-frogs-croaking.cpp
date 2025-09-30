class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {

    unordered_map<char,int> mpp;
    int frogs=0;
    int ans=0;
    if(croakOfFrogs[0]!='c' || croakOfFrogs.size()<5){
        return -1;
    }
    for(auto it: croakOfFrogs){
        if(it=='c'){
            if(mpp.count(it)){
                if(mpp[it]==mpp['k']){
                    mpp[it]++;

                }
                else{
                    ans++;
                    mpp[it]++;
                }
            }
            else{
                mpp[it]++;
                ans++;
            }
            frogs=max(frogs,ans);
        }
        else if(it=='r'){
            if(mpp.count(it)==0 && mpp['c']>0){
                mpp[it]++;
            }
            else if(mpp[it]<mpp['c']){
                mpp[it]++;
            }
            else{
                return -1;
            }


        }
        else if(it=='o'){
            if(mpp.count(it)==0 && mpp['r']>0){
                mpp[it]++;
            }
            else if(mpp[it]<mpp['r']){
                mpp[it]++;
            }
            else{
                return -1;
            }


        }
        else if(it=='a'){
            if(mpp.count(it)==0 && mpp['o']>0){
                mpp[it]++;
            }
            else if(mpp[it]<mpp['o']){
                mpp[it]++;
            }
            else{
                return -1;
            }


        }
        else if(it=='k'){
            if(mpp.count(it)==0 && mpp['a']>0){
                mpp[it]++;
            }
            else if(mpp[it]<mpp['a']){
                mpp[it]++;
            }
            else{
                return -1;
            }
            ans--;

        }
    } 
    if(mpp['c']!=mpp['r'] || mpp['r']!=mpp['o'] || mpp['o']!=mpp['a'] || mpp['a']!=mpp['k']){
        return -1;
    }
    return frogs;


        
    }
};