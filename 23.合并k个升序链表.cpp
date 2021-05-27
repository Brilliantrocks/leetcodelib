/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
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


// #include<vector>
// #include<queue>
// using namespace std;

//   struct ListNode {
//       int val;
//       ListNode *next;
//       ListNode() : val(0), next(nullptr) {}
//       ListNode(int x) : val(x), next(nullptr) {}
//       ListNode(int x, ListNode *next) : val(x), next(next) {}
//   };

class Solution {
public:
    struct compare
    {
        bool operator() (ListNode *l1,ListNode *l2){
            return l1->val > l2->val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        priority_queue<ListNode*,vector<ListNode*>,compare> pqueue;
        for (ListNode* x : lists){
            if(x) pqueue.emplace(x);
        }
        ListNode *ans= new ListNode(0), *cur=ans;
        while(!pqueue.empty()){
            cur->next = pqueue.top();
            cur = cur->next;
            pqueue.pop();
            if(cur->next) pqueue.emplace(cur->next);
        }
        return ans->next;
    }
};
// @lc code=end

