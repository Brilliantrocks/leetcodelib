/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
    stack<char> m_st;
    bool isValid(string s) {
        for(char x : s){
            switch(x){
                case '(':{
                    m_st.emplace('(');
                    break;
                }
                case '{':{
                    m_st.emplace('{');
                    break;
                }
                case '[':{
                    m_st.emplace('[');
                    break;
                }
                case ')':{
                    if(m_st.empty() || m_st.top()!='(') return false;
                    else m_st.pop();
                    break;
                }
                case '}':{
                    if(m_st.empty() || m_st.top()!='{') return false;
                    else m_st.pop();
                    break;
                }
                case ']':{
                    if(m_st.empty() || m_st.top()!='[') return false;
                    else m_st.pop();
                    break;
                }
            }
        }
        if(m_st.empty()) return true;
        else return false;
    }
};
// @lc code=end

