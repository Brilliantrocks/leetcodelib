/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
#include<stack>
using namespace std;

class MyQueue {
public:
    stack<int> stack_i,stack_o;
    /** Initialize your data structure here. */
    MyQueue() {}
    
    /** Push element x to the back of queue. */
    void push(int x) {
        int temp;
        while(!stack_o.empty()){
            temp=stack_o.top();
            stack_o.pop();
            stack_i.emplace(temp);
        }
        stack_i.emplace(x);
        while(!stack_i.empty()){
            temp=stack_i.top();
            stack_i.pop();
            stack_o.emplace(temp);
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int temp = stack_o.top();
        stack_o.pop();
        return temp;
    }
    
    /** Get the front element. */
    int peek() {
        return stack_o.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return stack_o.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

