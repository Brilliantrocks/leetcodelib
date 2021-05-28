/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) {
        if(!head||!(head->next)) return head;
        ListNode *cur=head,*ans=head->next,*temp=ans->next;
        head->next->next=cur;
        cur->next=temp;
        while(cur->next&&cur->next->next){
            temp=cur->next->next;
            cur->next->next=temp->next;
            temp->next=cur->next;
            cur->next=temp;
            cur=temp->next;
        }
        return ans;
    }
};
// @lc code=end

// class Solution {
// public:
//     ListNode* swapPairs(ListNode* head) {
//         if(!head||!(head->next)) return head;
//         ListNode *cur1=head,*cur2,*temp,*ans=head->next;
//         // head=head->next;
//         while(1){
//             cur2=cur1->next;
//             temp=cur2->next;
//             cur2->next=cur1;
//             if(temp==nullptr) {cur1->next = nullptr;break;}
//             else if(temp->next!=nullptr) cur1->next=temp->next;
//             else {cur1->next=temp;break;}
//             cur1=temp;
//         }
//         return ans;
//     }
// };