/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
每个右括号都有一个对应的相同类型的左括号。
输入：s = "()[]{}"
输出：true

输入：s = "(]"
输出：false
*/
#include <string>
#include <stack>
using namespace std;
class Solution {
    public:
    // 还是得用栈
    bool isValid(string s) {
        // 没有遇到匹配的，入栈，遇到匹配的，出栈，最后栈不空，返回false
        stack<char> result;
        for (char c : s) {
            if (!result.empty() && bingo(result.top(), c)){
                result.pop();
            }else {
                result.push(c);
            }
        }
        return result.empty();
    }
    bool bingo(const char c,const char cc){
        switch (c) {
            case '(':
            return cc==')';
            break;
            case '[':
            return cc==']';
            break;
            case '{':
            return cc=='}';
            break;
            default:
            return false;
        }
    }
};
