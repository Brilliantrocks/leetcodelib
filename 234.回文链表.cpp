/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head||!head->next) return true;
        ListNode *l1=head,*l2=head,*next,*prev=nullptr;
        while(l2->next&&l2->next->next){
            l1=l1->next;
            l2=l2->next->next;
        }
        l2=l1->next;
        while(l2){
            next=l2->next;
            l2->next=prev;
            prev=l2;
            l2=next;
        }
        while(prev){
            if(head->val != prev->val) return false;
            head=head->next;
            prev=prev->next;
        }
        return true;
    }
};
// @lc code=end

