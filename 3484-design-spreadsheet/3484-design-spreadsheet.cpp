class Spreadsheet {
public:
    vector<vector<int>> spreadsheet;
    Spreadsheet(int rows) {
        spreadsheet.resize(rows,vector<int>(26,0));

        
    }
    
    void setCell(string cell, int value) {
        char col=cell[0];
        string rem=cell.substr(1,cell.size()-1);
        int row=stoi(rem)-1;
        spreadsheet[row][col-'A']=value;
        
    }
    
    void resetCell(string cell) {
        char col=cell[0];
        string rem=cell.substr(1,cell.size()-1);
        int row=stoi(rem)-1;
        spreadsheet[row][col-'A']=0;
        
    }
    
    int getValue(string formula) {
        int ans=0;
        for(int i=1;i<formula.size();i++){
            if(formula[i]=='+'){
                continue;
            }
            else if(!isdigit(formula[i])){
                char alphabet=formula[i];
                i++;
                string val="";
                while(i<formula.size() && isdigit(formula[i])){
                    val.push_back(formula[i]);
                    i++;
                }
                i--;
                ans+=spreadsheet[stoi(val)-1][alphabet-'A'];
            }
            else if(isdigit(formula[i])){
                string val="";
                while(i<formula.size() && isdigit(formula[i])){
                    val.push_back(formula[i]);
                    i++;
                }
                i--;
                ans+=stoi(val);

            }

        }
        return ans;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */