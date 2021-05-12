/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */

// @lc code=start
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
// struct ListNode {
//       int val;
//       ListNode *next;
//       ListNode() : val(0), next(nullptr) {}
//       ListNode(int x) : val(x), next(nullptr) {}
//       ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         if (head != nullptr && (head->next) != nullptr)
//         {
//             ListNode* newhead = reverseList(head->next);    
//             (head->next)->next = head;
//             head->next = nullptr;
//             return newhead;
//         }

//     return head;
//     }
// };

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cru = head;
        while(cru!=nullptr){
            ListNode* temp = cru->next;
            cru->next = pre;
            pre = cru;
            cru = temp;
        }
    return pre;
    }
};
// @lc code=end
