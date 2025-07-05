/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* dummy = new Node(0);
        Node* curr2=dummy;
        Node* curr=head;
        map<Node*,Node*> mpp;
        while(curr){
            Node* temp=new Node(curr->val);
            mpp[curr]=temp;
           

            curr2->next=temp;
            curr2=curr2->next;
            curr=curr->next;
        }
        curr2=dummy->next;
        curr=head;
        while(curr){

            if(curr->random==nullptr){
                curr2->random=nullptr;
            }
            else{
                curr2->random=mpp[curr->random];
            }
            curr= curr->next;
            curr2=curr2->next;
        }
        return dummy->next;
    }
};