/*
 * @lc app=leetcode.cn id=382 lang=cpp
 *
 * [382] 链表随机节点
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

// #include<cstdlib>

// struct ListNode {
//       int val;
//       ListNode *next;
//       ListNode() : val(0), next(nullptr) {}
//       ListNode(int x) : val(x), next(nullptr) {}
//       ListNode(int x, ListNode *next) : val(x), next(next) {}
//   };
class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    ListNode *m_head;
    Solution(ListNode* head):m_head(head){}
    
    /** Returns a random node's value. */
    int getRandom() {
        ListNode *node = m_head->next;
        int ans = m_head->val;
        int i =2;
        while(node){
            // 返回第i个节点的值概率为1/i 且之后的都不覆盖ans
            // 即总概率为 1/i * i/(i+1) * (i+1)/(i+2).....(n-1)/n = 1/n
            if(!(rand()%i)){
                ans = node->val;
            }
            ++i;
            node=node->next;   
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
// @lc code=end

