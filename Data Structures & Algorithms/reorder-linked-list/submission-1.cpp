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
    void reorderList(ListNode* head) {
        vector<ListNode*> v;
        if(head == nullptr){
            return;
        }
        ListNode* temp =  head;
        while(temp!=nullptr){
            v.push_back(temp);
            temp = temp->next;
        }
        int n = v.size();
        int i =0; int j = v.size()-1;
        while(i<j){
            if(i==j) {
                break;
            }
            v[i]->next = v[j];
            i++;
            
            v[j]->next = v[i];
            j--;
        }
        v[i]->next = nullptr;
    }
};
