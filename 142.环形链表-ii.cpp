/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// struct ListNode {
//      int val;
//      ListNode *next;
//      ListNode(int x) : val(x), next(nullptr) {}
// };

// 指针f l 
// vf = 2 vl =1
// 若有环 则 sf-sl = n （n为环长） 时相遇
// 令环前长m 此时 sf = m + n + x; sl = m + x 
// x为环起点至相遇点的距离
// 且 sf = 2sl 有 m + x = n x = n - m m = n - x
// 则从相遇点再行进m距离可以回到环起点
// 若从起点同步同速移动m长 则相遇于环起点

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *f = head, *s = head;
        do {
            if (!f || !f->next) return nullptr;
            f = f->next->next;
            s = s->next;
        }while(f != s);
        f = head;
        while(f != s){
            f = f->next;
            s = s->next;
        }
        return f;
    }
};
// @lc code=end

