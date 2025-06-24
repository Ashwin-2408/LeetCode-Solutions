class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        int is_number=1;
        vector<int> results;

        for(int i=0;i<expression.size();i++){
            if(!isdigit(expression[i])){
                is_number=0;
                vector<int> left =diffWaysToCompute(expression.substr(0,i));
                vector<int> right=diffWaysToCompute(expression.substr(i+1,expression.size()-i-1));

                for(auto it :right){
                    for(auto ele:left){
                        int res=0;
                        switch(expression[i]){
                            case '*': 
                                res=it*ele;
                                break;
                            case '+':
                                res=it+ele;
                                break;
                            case '-':
                                res=ele-it;
                                break;
                        }
                        results.push_back(res);


                    }
                }


            }
            
            
        }
        if(is_number==1){
                results.push_back(stoi(expression));
        }
        return results;
        
    }
};