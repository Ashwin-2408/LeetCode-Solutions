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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int,int> mpp;
        for(auto it: nums){
            mpp[it]++;

        }
        ListNode* dumm=new ListNode(0);
        ListNode* curr=head;
        ListNode* prev=dumm;
        while(curr){
            if(mpp.count(curr->val)!=0){
                curr=curr->next;
                continue;
            }
            else{
                prev->next=curr;
                prev=prev->next;
                curr=curr->next;
            }
        }
        prev->next=nullptr;
        return dumm->next;


        
    }
};