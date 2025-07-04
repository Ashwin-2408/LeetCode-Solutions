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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int count=0;
        vector<ListNode*> ans;
        ListNode* curr=head;
        while(curr){
            count++;
            curr=curr->next;
        }
        if(count<k){
            curr=head;
            while(k--){
                if(curr){
                    ans.push_back(curr);
                    ListNode * temp=curr;
                    
                    curr=curr->next;
                    temp->next=nullptr;
                }
                else{
                    ans.push_back(nullptr);
                }
               
                

            }
        }
        else if(count ==k){
            curr=head;
            while(k--){
                if(curr){
                    ans.push_back(curr);
                    ListNode * temp=curr;
                    curr=curr->next;
                    
                    temp->next=nullptr;
                }
                

            }
        }
        else{
            int groups=count/k;
            int extra_groups=count%k;
            curr=head;
            while(curr){
            if(extra_groups>0){
                ans.push_back(curr);

                for(int i=1;i<groups+1;i++){
                    curr=curr->next;
                
                }
                
                ListNode* temp=curr;
                curr=curr->next;
                temp->next=nullptr;
                extra_groups--;
            }
            else{
                 ans.push_back(curr);
                for(int i=1;i<groups;i++){
                    curr=curr->next;
                
                }
               
                ListNode* temp=curr;
                curr=curr->next;
                temp->next=nullptr;
                

            }
            }
            


        }
        return ans;
        
    }
};