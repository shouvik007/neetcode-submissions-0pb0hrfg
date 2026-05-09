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
    ListNode* mergeTwoSorted (ListNode* lists1, ListNode* lists2) {
        ListNode* head = new ListNode();
        ListNode* temp = head;
        head = temp;
        while(lists1!=nullptr && lists2!= nullptr) {
            if(lists1->val >= lists2->val){
                temp ->next = lists2;
                lists2 = lists2->next;
            }
            else {
                temp->next = lists1;
                lists1 = lists1->next;
            }
            temp = temp->next;
        }
        if(lists1!=nullptr) {
            temp->next = lists1;

        }
        else if (lists2!=nullptr){
            temp->next = lists2;
        }
        return head->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int>v;
        ListNode* temp = nullptr;
        for(int i=0;i<lists.size();i++){
            ListNode* lists1= lists[i];
            temp = mergeTwoSorted(lists1, temp);
        }
        return temp;
    }
};
