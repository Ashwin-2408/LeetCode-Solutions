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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr){
            return head;
        }
        unordered_map<int,int> mpp;
        mpp[head->val]++;

        ListNode* prev=head;
        ListNode* curr=head->next;
        while(curr && prev){
            if(mpp.find(curr->val)!=mpp.end()){
                prev->next=prev->next->next;
            }
            else{
                mpp[curr->val]++;
                prev=prev->next;
            }
            curr=curr->next;
        }
        return head;

        
    }
};