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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp=head->next;
        
        while(temp!=NULL){
            ListNode* curr=temp->next;
            if(curr->val==0){
                temp->next=curr->next;
                temp=temp->next;
            }
            else{
                temp->val += curr->val;
                temp->next=curr->next;
            }
        }
        return head->next;
    }
};