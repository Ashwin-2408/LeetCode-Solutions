/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* newhead= new ListNode();
        ListNode* curr_new=newhead;
        ListNode* curr= head;
        int val=0;
        while(curr){
            if(curr->val==0 && val!=0){
                newhead->next=new ListNode(val);
                newhead=newhead->next;
                val=0;
            }
            else if(curr->val!=0){
                val+=curr->val;

            }
            curr=curr->next;

        }
        if(val>0){
            newhead->next=new ListNode(val);
        }
        return curr_new->next;
        
    }
};