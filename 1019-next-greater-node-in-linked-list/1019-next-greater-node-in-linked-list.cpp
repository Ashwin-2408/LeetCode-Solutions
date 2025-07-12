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
        while(head){
            ListNode* temp=head->next;
            head->next=prev;
            prev=head;
            head=temp;
        }
        return prev;
    }
    vector<int> nextLargerNodes(ListNode* head) {
        head=reverse_list(head);
        stack<int> s;
        vector<int> ans;
        while(head){
            while(!s.empty() && s.top()<=head->val){
                s.pop();
            }
            
            if(s.empty()){
                ans.push_back(0);
            }
            else{
                ans.push_back(s.top());
            }
            s.push(head->val);
            head=head->next;
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};