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
    ListNode* swapNodes(ListNode* head, int k) {
        int length=0;
        ListNode* curr=head;
        while(curr){
            length++;
            curr=curr->next;
        }
        int starting=k-1;
        int ending=length-k;
        ListNode* left=head;
        ListNode* right=head;
        ListNode* left_prev=nullptr;
        ListNode* right_prev=nullptr;
        while(starting){
            if(starting==1){
                left_prev=left;
            }
            left=left->next;
            starting--;
            

        }
        while(ending){
            if(ending==1){
                right_prev=right;
            }
            right=right->next;
            ending--;
        }
        int temp=left->val;
        left->val=right->val;
        right->val=temp;
        return head;
    }
};