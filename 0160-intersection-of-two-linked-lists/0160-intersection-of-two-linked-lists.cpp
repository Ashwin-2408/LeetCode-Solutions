/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;
        ListNode* currA=headA;
        ListNode* currB=headB;
        int loop=0;
        while(headA!=headB){
            if(loop>2){
                break;
            }
            headA=headA->next;
            headB=headB->next;
            if(headA==nullptr){
                headA=currB;
                loop++;
            }
            if(headB==nullptr){
                headB=currA;
                loop++;
            }
        }
        if(loop>2){
            return nullptr;
        }
        return headA;
    }
};