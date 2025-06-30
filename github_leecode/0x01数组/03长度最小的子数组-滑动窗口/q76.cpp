/*
 * 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。

 注意：

 对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。
 如果 s 中存在这样的子串，我们保证它是唯一的答案。

 输入：s = "ADOBECODEBANC", t = "ABC"
 输出："BANC"
 解释：最小覆盖子串 "BANC" 包含来自字符串 t 的 'A'、'B' 和 'C'。
 */
#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;
class Solution{
    public:
    // 滑动窗口，但是while判断条件复杂度太高，最后两个测试用例过不了
    string minWindow(string s, string t) {
        int start = 0, s_len = s.length();
        int result_start=-1, result_end=s_len;
        int result_len = result_end - result_start + 1;
        unordered_map<char, int> tmp;
        for (int end = 0; end < s_len; end++) {
            tmp[s[end]]++;
            // 如果包含:全部在 and 次数大于
            while (ifBigger(tmp, t)) {
                if (result_len > end-start+1) {
                    result_len = end-start+1;
                    result_end = end;
                    result_start = start;
                }
                tmp[s[start++]]--;
            }
        }
        if (result_start == -1) {
            return "";
        }
        return s.substr(result_start,result_end-result_start+1);
    }
    bool ifBigger(unordered_map<char, int> tmp, string t){
        unordered_map<char, int> tt;
        for (char item : t) {
            tt[item]++;
        }
        for (const auto& [ch, cnt] : tt) {
            if (tmp[ch] < cnt) return false;
        }
        return true;
    }
};

int main(int argc, char* argv[]){
    Solution app;
    // cout <<  app.minWindow(argv[1], argv[2]);
    cout <<  app.minWindow2(argv[1], argv[2]);
    return 0;
}
