/*
给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和并同样以字符串形式返回。

你不能使用任何內建的用于处理大整数的库（比如 BigInteger）， 也不能直接将输入的字符串转换为整数形式。
输入：num1 = "11", num2 = "123"
输出："134"
*/
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

template <typename T>
void printVector(const vector<T>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i];
        if (i != vec.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}


class Solution{
    public:
    // 不让用库，也不让直接转换，意思是只能一位一位加呗
    string addStrings(string num1, string num2) {
        // 进位
        int over = 0;
        // 结果
        vector<int> res = {};
        // 反排数组
        vector<int> num1s = stringToVec(num1);
        vector<int> num2s = stringToVec(num2);
        // 补零
        int cha = num1s.size() - num2s.size();
        while (cha>0) {
            num2s.push_back(0);
            cha--;
        }
        while (cha<0) {
            num1s.push_back(0);
            cha++;
        }
        int len = num1s.size();
        // 计算逻辑
        for(int i=0; i<len; i++){
            res.push_back((over + num1s[i] + num2s[i]) % 10);
            over = (over + num1s[i] + num2s[i]) / 10;
        }
        // 最后一位进位
        if (over){
            res.push_back(over);
        }
        return vecToString(res);
    }
    vector<int> stringToVec(string &num){
        vector<int> result = {};
        for (char item : num) {
            result.push_back(item-'0');
        }
        reverse(result.begin(),result.end());
        return result;
    }
    string vecToString(vector<int> &res){
        ostringstream oss;
        reverse(res.begin(),res.end());
        for (auto item : res) {
            oss << item;
        }
        return oss.str();
    }
};

int main() {
    Solution solution;

    // 测试用例 1：普通情况，无进位
    string num1 = "584";
    string num2 = "18";
    string result = solution.addStrings(num1, num2);
    cout << "Test Case 1: " << (result == "602" ? "Passed" : "Failed") << " | Output: " << result << endl;

    // 测试用例 2：有进位
    num1 = "456";
    num2 = "77";
    result = solution.addStrings(num1, num2);
    cout << "Test Case 2: " << (result == "533" ? "Passed" : "Failed") << " | Output: " << result << endl;

    // 测试用例 3：不同长度的字符串
    num1 = "1";
    num2 = "999";
    result = solution.addStrings(num1, num2);
    cout << "Test Case 3: " << (result == "1000" ? "Passed" : "Failed") << " | Output: " << result << endl;

    // 测试用例 4：全零的情况
    num1 = "0";
    num2 = "0";
    result = solution.addStrings(num1, num2);
    cout << "Test Case 4: " << (result == "0" ? "Passed" : "Failed") << " | Output: " << result << endl;

    // 测试用例 5：一个字符串为零
    num1 = "0";
    num2 = "12345";
    result = solution.addStrings(num1, num2);
    cout << "Test Case 5: " << (result == "12345" ? "Passed" : "Failed") << " | Output: " << result << endl;

    // 测试用例 6：两个大数相加
    num1 = "987654321987654321";
    num2 = "123456789123456789";
    result = solution.addStrings(num1, num2);
    cout << "Test Case 6: " << (result == "1111111111111111110" ? "Passed" : "Failed") << " | Output: " << result << endl;

    return 0;
}
