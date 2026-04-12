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
    ListNode* findmid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=nullptr && fast->next !=nullptr){
            fast = fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* l2) {
        ListNode* curr;
        curr = l2;
        ListNode* prev = nullptr;
        ListNode* next;
        while(curr!=nullptr){
            next = curr->next;
            curr->next = prev;
            prev= curr;
            curr= next;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        ListNode* mid = findmid(head);
        ListNode*l2= reverse(mid->next);
        mid->next = nullptr;
        ListNode* temp = head;
        while(temp!=nullptr&&l2!=nullptr){
            ListNode* curr1 = temp->next;
            ListNode* curr2 = l2->next;
            temp->next = l2;
            l2->next = curr1;
            temp = curr1;
            l2= curr2;
        }
    }
};
