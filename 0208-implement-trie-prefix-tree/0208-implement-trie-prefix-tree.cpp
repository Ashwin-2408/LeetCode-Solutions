class Node {
    public:
    Node* Links[26];
    bool flag=false;

    void put(char c,Node* node){
        Links[c-'a']=node;
    }
    Node* get(char c){
        return Links[c-'a'];
    }
    void set_end(Node* node){
        node->flag=true;

    }
    bool contains_key(char c){
        return Links[c-'a']!=nullptr;
    }

};


class Trie {
    private:
     Node* root;
public:
    Trie() {
         root=new Node();
    }
    
    void insert(string word) {
        Node* curr=root;
        for(int i=0;i<word.size();i++){
            if(!curr->contains_key(word[i])){
            curr->put(word[i],new Node());
            
            }
            curr=curr->get(word[i]);
        }
        curr->set_end(curr);
        
        
    }
    
    bool search(string word) {
        Node* curr = root;
        for(auto it :word){
            if(curr->contains_key(it)){
                curr=curr->get(it);

            }
            else{
                return false;
            }
            
        }
        if(curr->flag==true){
            return true;
        }
        return false;
        
    }
    
    bool startsWith(string prefix) {
         Node* curr = root;
        for(auto it :prefix){
            if(curr->contains_key(it)){
                curr=curr->get(it);

            }
            else{
                return false;
            }
            
        }
        return true;
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */