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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        ListNode* curr = head;
        for(int i =1;i<left;i++){
            prev = curr;
            curr = curr->next;
        }
        ListNode* tail = curr;
        ListNode* leftprev = nullptr;
        ListNode* next = curr;
        for(int i = 0;i<=right-left;i++){
            next = curr->next;
            curr->next = leftprev;
            leftprev = curr;
            curr= next;
        }

        prev->next = leftprev;
        tail->next = curr;

        
        return dummy.next;

    }
};