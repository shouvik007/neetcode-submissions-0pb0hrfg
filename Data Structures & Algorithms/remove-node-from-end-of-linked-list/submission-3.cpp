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
        if(x ==0){
            return head->next;
        }
        v[x-1]->next = v[x]->next;
        return head;
    }
};
