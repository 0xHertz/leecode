/*
给你两个 版本号字符串 version1 和 version2 ，请你比较它们。版本号由被点 '.' 分开的修订号组成。修订号的值 是它 转换为整数 并忽略前导零。

比较版本号时，请按 从左到右的顺序 依次比较它们的修订号。如果其中一个版本字符串的修订号较少，则将缺失的修订号视为 0。

返回规则如下：

如果 version1 < version2 返回 -1，
如果 version1 > version2 返回 1，
除此之外返回 0。

输入：version1 = "1.2", version2 = "1.10"
输出：-1

输入：version1 = "1.01", version2 = "1.001"
输出：0

输入：version1 = "1.0", version2 = "1.0.0.0"
输出：0
*/
#include <string>
#include <vector>
#include <sstream>
using namespace std;
class Solution{
    public:
    int compareVersion(string version1, string version2) {
        // 分割
        vector<int> v1 = split(version1, '.');
        vector<int> v2 = split(version2, '.');
        // 补零
        while (v1.size() < v2.size()) {
            v1.push_back(0);
        }
        while (v2.size() < v1.size()) {
            v2.push_back(0);
        }
        int len1 = v1.size();
        // 比较
        for (int i=0; i<len1; i++) {
            if (v1[i] < v2[i]) {
                return -1;
            } else if (v1[i] > v2[i]) {
                return 1;
            }
        }
        return 0;  // 相等

    }
    vector<int> split(string version, char c) {
        vector<int> result;
        istringstream iss(version);  // 创建字符串流
        string token;

        while (getline(iss, token, c)) {  // 按指定分隔符读取
            result.push_back(stoi(token));  // 转换为整数并添加到结果向量
        }

        return result;
    }
};
