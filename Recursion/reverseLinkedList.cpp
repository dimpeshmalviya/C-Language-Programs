class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // Base case: empty list or single node
        if (head == nullptr || head->next == nullptr)
            return head;
        
        // Recursively reverse the rest of the list
        ListNode* newHead = reverseList(head->next);
        
        // Reverse the current node's pointer
        head->next->next = head;
        head->next = nullptr;
        
        return newHead;
    }
};
