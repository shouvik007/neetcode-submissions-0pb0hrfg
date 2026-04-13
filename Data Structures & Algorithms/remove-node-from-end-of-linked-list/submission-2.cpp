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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*>v;
        ListNode* temp = head;
        while(temp != nullptr){
            v.push_back(temp);
            temp = temp ->next;
        }
       int x = v.size()-n;
       ListNode* dummy= new ListNode(0); 
        ListNode* curr = dummy;
       for(int i =0;i<v.size();i++){
            if(i!=x) {
                curr->next = v[i];
                curr=curr->next;
            }
       }
       curr->next = nullptr;
       return dummy->next;
    }
};
