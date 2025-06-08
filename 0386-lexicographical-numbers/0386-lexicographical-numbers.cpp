class Trie {
public:
    Trie* Links[10];
    bool is_end = false;

    void add_node(int val) {
        string s = to_string(val);
        Trie* curr = this;
        for (auto it : s) {
            if (curr->Links[it - '0'] == nullptr) {
                curr->Links[it - '0'] = new Trie();
            }
            curr = curr->Links[it - '0'];
        }
        curr->is_end = true;
    }
};

class Solution {
public:
    Trie* root = new Trie();
    vector<int> lexicalOrder(int n) {
        for (int i = 1; i <= n; i++) {
            root->add_node(i);
        }
        vector<int> result;
        dfs(root,"",result);
        return result;
      
    }

    void dfs(Trie* root,string path,vector<int>& result){
        if(root->is_end==true){
            result.push_back(stoi(path));
        }
        for(int i=0;i<10;i++){
            if(root->Links[i]!=nullptr){
            dfs(root->Links[i],path+char(i+'0'),result);
            }
        }
    }
};