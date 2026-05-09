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
    ListNode* reverse(ListNode* head ){
        if(head==nullptr) {
            return nullptr;
        }
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* newNode = nullptr;
        while(curr!=nullptr){
            newNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = newNode;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* curr = head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prevGroupTail = dummy;
        int count = 0;
        while(curr!=nullptr){
            if(count == k-1){
                ListNode* nextseg = nullptr;
                nextseg = curr->next;
                curr->next = nullptr;
                ListNode* reversedHead = reverse(temp);
                prevGroupTail->next = reversedHead;
                temp->next = nextseg;
                prevGroupTail = temp;
                curr = nextseg;
                temp = nextseg;
                count = 0;
            }
            else {
                count ++;
                curr= curr->next;
            }
        }
        return dummy->next;
    }
};
