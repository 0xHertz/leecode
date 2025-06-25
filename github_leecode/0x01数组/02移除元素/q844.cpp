/*
给定 s 和 t 两个字符串，当它们分别被输入到空白的文本编辑器后，如果两者相等，返回 true 。# 代表退格字符。

注意：如果对空文本输入退格字符，文本继续为空。

示例 1：

输入：s = "ab#c", t = "ad#c"
输出：true
解释：s 和 t 都会变成 "ac"。
*/
#include <string>
#include <iostream>
using namespace std;
class Solution{
    public:
    bool backspaceCompare(string s, string t) {
        int res1 = 0, res2 = 0;
        for (char str : s) {
            if (str != '#') {
                s[res1++] = str;
            }else{
                res1 = res1 >= 1 ? res1-1 : 0;
            }
        }
        for (char str : t) {
            if (str != '#') {
                t[res2++] = str;
            }else{
                res2 = res2 >= 1 ? res2-1 : 0;
            }
        }
        if (res1 != res2) return false;//先判断两个指针的长度是否一样
        for (int i = 0; i < res1; i++)//再按位遍历覆盖值后的两个字符串
            if (s[i] != t[i]) return false;
        return true;
    }
};

int main(int argc, char* argv[]){
    Solution app;
    cout << app.backspaceCompare(string{"ab##"},string{"c#d#"}) << endl;
    return 0;
}
