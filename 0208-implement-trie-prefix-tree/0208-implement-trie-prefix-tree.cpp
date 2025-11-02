class Node{
    public:
        bool isend;
        Node* links[26];

        Node(){
            isend=false;
            for(int i=0;i<26;i++){
                links[i]=nullptr;
            }

        }

};
class Trie {
public:
    Node* root;
    Trie() {
        root=new Node();
        
    }
    
    void insert(string word) {
        Node* curr=root;
        for(auto it: word){
            if(!curr->links[it-'a']){
                Node* new_node=new Node();
                curr->links[it-'a']=new_node;
            }
            curr=curr->links[it-'a'];
        }
        curr->isend=true;
    }
    
    bool search(string word) {
        Node* curr=root;
        for(auto it: word){
            if(!curr->links[it-'a']){
                return false;
            }
            curr=curr->links[it-'a'];

        }
        if(curr->isend){
            return true;
        }
        return false;;
        
    }
    
    bool startsWith(string prefix) {
        Node* curr=root;
        for(auto it: prefix){
            if(!curr->links[it-'a']){
                return false;
            }
            curr=curr->links[it-'a'];

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