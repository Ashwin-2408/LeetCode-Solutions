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
    ListNode* reverse_list(ListNode* head){
        ListNode* prev=nullptr;
        ListNode* curr=head;
        while(curr){
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right){
            return head;
        }
        ListNode* prev=new ListNode();
        prev->next=head;
        ListNode* dummy=prev;
        for(int i=1;i<left;i++){
            dummy=dummy->next;
        }
        ListNode* start=dummy->next;
        ListNode* end=start;
        for(int i=left;i<right;i++){
            end=end->next;
        }
        ListNode* next= end->next;
        end->next=nullptr;
        ListNode* reverse=reverse_list(start);
        dummy->next=reverse;
        start->next=next;

        return prev->next;
        
        


        
        
    }
};