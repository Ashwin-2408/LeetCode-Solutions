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
    ListNode* curr;
    ListNode* trav;
    Solution(ListNode* head) {
        curr=head;
      
        
    }
    
    int getRandom() {
        
        int res=0;
        int nodes=1;
        for(ListNode* start=curr;start!=nullptr;start=start->next){
            if(rand()%nodes==0){
                res=start->val;
            }
            nodes++;
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */