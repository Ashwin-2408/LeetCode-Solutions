class Node{
public:
    Node* Links[27];
    bool flag=false;

    void put(char c){
        Links[c-'a']=new Node();
    }
    Node* get(char c){
        return Links[c-'a'];
    }
    bool contains_key(char c){
        return Links[c-'a'];
    }
    void set_end(){
        flag=true;
    }
};

class WordDictionary {
private:
    Node* root;
public:
    WordDictionary() {
        root = new Node();
    
    }
    
    void addWord(string word) {
        Node* curr= root;
        for(auto it : word){
            if(!curr->contains_key(it)){
                curr->put(it);
            }
            curr=curr->get(it);
        }
        curr->set_end();
        
    }
    
    bool search(string word) {
       return search_helper(root,word,0);

        
    }
    bool search_helper(Node* node,string word,int index){
        if(index==word.size()){
            return node->flag;
        }
        if(word[index]=='.'){
            for(auto it:node->Links){
                
                if(it!=nullptr &&search_helper(it,word,index+1)){
                    return true;
                }
            }
        }
        else{
            if(!node->contains_key(word[index])){
                return false;
            }
            node=node->get(word[index]);
            return search_helper(node,word,index+1);
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */