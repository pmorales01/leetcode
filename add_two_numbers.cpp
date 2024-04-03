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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {        
        int carry = 0;
        
        // create the dummy node to be the new head
        ListNode* dummy = new ListNode();

        ListNode* sol = dummy;

        // if carry = 1 (true, add a new node to represent carrying 1s)
        while (l1 != nullptr || l2 != nullptr || carry) {
            // 1. check if nullptr 2. add 0 if nullptr, else val
            // 3. add carry from previous addition
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            
            // carry if sum > 10
            carry = sum / 10;

            //create a new node
            sol->next = new ListNode(sum % 10);
            
            // point to the new node
            sol = sol -> next;

            // if not null, point to the next node in the lists
            if (l1) l1 = l1->next;

            if (l2) l2 = l2->next;
        }

        return dummy->next;
    }
};
