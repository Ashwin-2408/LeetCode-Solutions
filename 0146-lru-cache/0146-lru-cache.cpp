class Node{
    public:
    Node* next=nullptr;
    Node* rear=nullptr;
    int key=-1;
    int val=-1;
    Node(){

    }
    Node(int key,int val){
        this->key=key;
        this->val=val;


    }
};
class LRUCache {
public:
    unordered_map<int,int> cache;
    int size=0;
    int max_size=0;
    Node* head=new Node();
    Node* tail=new Node();
    LRUCache(int capacity) {
        max_size=capacity;
        
        head->next=tail;
        tail->rear=head;

        
    }
    void add_front(int key,int value){
        Node* new_node=new Node(key,value);
        
        
        new_node->next=head->next;
        new_node->next->rear=new_node;
        new_node->rear=head;
        head->next=new_node;
    }
    void remove(int key){
        Node* curr=head;
        while(curr){
            if(curr->key==key){
                curr->rear->next=curr->next;
                curr->next->rear=curr->rear;
                break;
            }
            curr=curr->next;
        }
    }
    
    int get(int key) {
        if(cache.find(key)==cache.end()){
            return -1;
        }
        else{
            
            remove(key);
            add_front(key,cache[key]);

            return cache[key];
        }
        
    }
    
    void put(int key, int value) {
        
        if(cache.find(key)!=cache.end()){
            remove(key);
            add_front(key,value);
            cache[key]=value;
        
        }
        else if(cache.size()>=max_size){
            cache.erase(tail->rear->key);
            remove(tail->rear->key);
            
            add_front(key,value);
            cache[key]=value;

        }
        else{
            add_front(key,value);
            cache[key]=value;
           
        }

        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */