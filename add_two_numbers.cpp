#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* curr = &dummy;
        int carry = 0;
        
        while (l1 || l2 || carry) {
            int sum = carry;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
        }
        return dummy.next;
    }
};
ListNode* createList(int arr[], int n) {
    if (n == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;
    for (int i = 1; i < n; i++) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution s;
    
    // Example 1: 342 + 465 = 807
    // Lists store digits in reverse: [2,4,3] + [5,6,4] = [7,0,8]
    int arr1[] = {2, 4, 3};
    int arr2[] = {5, 6, 4};
    ListNode* l1 = createList(arr1, 3);
    ListNode* l2 = createList(arr2, 3);
    
    cout << "List 1: ";
    printList(l1);
    cout << "List 2: ";
    printList(l2);
    
    ListNode* result = s.addTwoNumbers(l1, l2);
    cout << "Result: ";
    printList(result);
    cout << endl;
    
    // Example 2: 0 + 0 = 0
    int arr3[] = {0};
    int arr4[] = {0};
    ListNode* l3 = createList(arr3, 1);
    ListNode* l4 = createList(arr4, 1);
    
    cout << "List 3: ";
    printList(l3);
    cout << "List 4: ";
    printList(l4);
    
    ListNode* result2 = s.addTwoNumbers(l3, l4);
    cout << "Result: ";
    printList(result2);
    cout << endl;
    
    // Example 3: 9999999 + 9999 = 10009998
    // [9,9,9,9,9,9,9] + [9,9,9,9] = [8,9,9,9,0,0,0,1]
    int arr5[] = {9, 9, 9, 9, 9, 9, 9};
    int arr6[] = {9, 9, 9, 9};
    ListNode* l5 = createList(arr5, 7);
    ListNode* l6 = createList(arr6, 4);
    cout << "List 5: ";
    printList(l5);
    cout << "List 6: ";
    printList(l6);
    ListNode* result3 = s.addTwoNumbers(l5, l6);
    cout << "Result: ";
    printList(result3);
     return 0;
}