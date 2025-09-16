class Solution {
public:
    int gcd(int a,int b){
        if(a<b){
            return gcd(b,a);
        }
        while(b!=0){
            int temp=b;
            b=a%b;
            a=temp;
            

        }
        return a;
    }
    long long lcm(long long a,long long b){
        return ((a)/(gcd(a,b)))*b;
    }
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int> s;
        s.push(nums[0]);
        int i=1;
        while(i<nums.size()){
            int x=nums[i];
            while(!s.empty() && gcd(s.top(),x)>1){
                x=lcm(s.top(),x);
                s.pop();


            }
            
            s.push(x);
            i++;
    
        }
        vector<int> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
            
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
        
    }
};