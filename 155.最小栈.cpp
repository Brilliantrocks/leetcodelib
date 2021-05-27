/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
#include<stack>
using namespace std;

class MinStack {
public:
    stack<int> m_st,m_min;
    /** initialize your data structure here. */
    MinStack() {}
    
    void push(int val) {
        if(m_min.empty()||val<=m_min.top()) {
            m_min.emplace(val);
        }
        m_st.emplace(val);
    }
    
    void pop() {
        if(m_st.top()==m_min.top()){
            m_min.pop();
        }
        m_st.pop();
    }
    
    int top() {
        return m_st.top();
    }
    
    int getMin() {
        return m_min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

