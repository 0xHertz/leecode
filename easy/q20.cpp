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
using namespace std;
class Solution {
    public:
    // 第一反应：用栈
    // 第二反应：只需要计算数量就行
    // 错误的，题目理解有误，"([)]"应返回false
    bool isValid(string s) {
        if (countX('(', s) != countX(')', s)){
            return false;
        } else if (countX('[', s) != countX(']', s)){
            return false;
        } else if (countX('{', s) != countX('}', s)){
            return false;
        } else {
            return true;
        }
    }
    int countX(const char x,string &str){
        int sum = 0;
        for (char c : str){
            if (c == x){
                ++sum;
            }
        }
        return sum;
    }
};
