/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode *ans,*cur;
        if(l1->val > l2->val) {
            ans=cur=l2;
            l2=l2->next;
        }
        else {
            ans=cur=l1;
            l1=l1->next;
        }
        while(1){
            if(l1==nullptr) {cur->next=l2; break;}
            if(l2==nullptr) {cur->next=l1; break;}
            if(l1->val > l2->val) {
                cur->next=l2;
                cur=l2;
                l2=l2->next;
            }
            else{
                cur->next=l1;
                cur=l1;
                l1=l1->next;
            }
        }
        return ans;
    }
};
// @lc code=end
// 递归
// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
//         if(!l1) return l2;
//         if(!l2) return l1;
//         if(l1->val > l2->val){
//             l2->next = mergeTwoLists(l1,l2->next);
//             return l2;
//         }
//         else {
//             l1->next = mergeTwoLists(l1->next,l2);
//             return l1;
//         }
//     }
// };