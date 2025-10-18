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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head; 
        ListNode *newHead = new ListNode(0);
        ListNode *curr = head, *prev = newHead, *n1, *n2;

        while(curr && curr->next){
            n1 = curr;
            n2 = curr->next;
            prev->next = n2;
            n1->next = n2->next;
            n2->next = n1;
            curr = n1->next;
            prev = n1;
        }

        return newHead->next;
    }
};
