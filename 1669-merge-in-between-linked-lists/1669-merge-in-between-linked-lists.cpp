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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* curr=list1;
        for(int i=0;i<a-1;i++){
            curr=curr->next;

        }
        ListNode* temp=curr->next;
        curr->next=list2;
        ListNode* head=list2;
        while(head->next){
            head=head->next;
        }
        for(int i=a;i<=b;i++){
            temp=temp->next;
        }
        head->next=temp;
        return list1;
        
    }
};