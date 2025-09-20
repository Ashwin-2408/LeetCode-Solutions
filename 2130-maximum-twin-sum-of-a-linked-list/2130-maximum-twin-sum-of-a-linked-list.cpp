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
    int pairSum(ListNode* head) {
        int length=0;
        ListNode* curr=head;
        while(curr){
            length++;
            curr=curr->next;
        }
        vector<int> arr(length/2,0);
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;

        }
        fast=head;
        int i=0;
        int j=(length/2)-1;
        while(slow){
            arr[i]+=fast->val;
            arr[j]+=slow->val;
            i++;
            j--;
            fast=fast->next;
            slow=slow->next;
        }
        return *max_element(arr.begin(),arr.end());

        
    }
};