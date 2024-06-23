/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

// @lc code=start


//  struct ListNode {
//       int val;
//      ListNode *next;
//      ListNode() : val(0), next(nullptr) {}
//      ListNode(int x) : val(x), next(nullptr) {}
//      ListNode(int x, ListNode *next) : val(x), next(next) {}
//  };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode;
        ListNode* ans = head;
        int moveUp = 0;
        int val1, val2, sum;

        if(l1 != nullptr && l2 != nullptr){
            val1 = l1->val;
            val2 = l2->val;
            sum = val1 + val2 + moveUp;
            moveUp = sum / 10;
            head->val = sum % 10;


            l1 = l1 -> next;
            l2 = l2 -> next;
            head -> next = new ListNode;
        }

        while(l1 != nullptr && l2 != nullptr){
            head = head -> next;
            val1 = l1->val;
            val2 = l2->val;
            sum = val1 + val2 + moveUp;
            head->val = sum % 10;

            moveUp = sum / 10;

            l1 = l1 -> next;
            l2 = l2 -> next;
            head -> next = new ListNode;
        }

        if(l1 == nullptr && l2 != nullptr){
            l1 = l2;
        }

        while(l1 != nullptr){
            head = head -> next;
            sum = l1 -> val + moveUp;
            moveUp = sum / 10;
            head -> val = sum % 10;

            l1 = l1 -> next;
            head -> next = new ListNode;
        }

        if(moveUp != 0){
            head = head -> next;
            head -> val = moveUp;
        }

        head -> next = nullptr;
        return ans;
    }
};
// @lc code=end

