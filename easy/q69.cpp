/*
给你一个非负整数 x ，计算并返回 x 的 算术平方根 。

由于返回类型是整数，结果只保留 整数部分 ，小数部分将被 舍去 。

注意：不允许使用任何内置指数函数和算符，例如 pow(x, 0.5) 或者 x ** 0.5 。
*/
#include <iostream>
using namespace std;
class Solution {
    public:
    int mySqrt(int x) {
        int left = 0;
        int right = x;
        int middle = 0;
        int tmp;
        if (x==1) {
            return 1;
        }
        while (left < right-1) {
            middle = left + (right - left)/2;
            tmp = middle * middle;
            if (tmp > x) {
                right = middle;
            }else if (tmp < x) {
                left = middle;
            }else {
                return middle;
            }
        }
        return middle;
    }
};

int main() {
    Solution solution;

    // Test case 1: x = 0
    cout << "Test case 1: x = 0" << endl;
    cout << "Expected: 0" << endl;
    cout << "Output: " << solution.mySqrt(0) << endl;
    cout << endl;

    // Test case 2: x = 1
    cout << "Test case 2: x = 1" << endl;
    cout << "Expected: 1" << endl;
    cout << "Output: " << solution.mySqrt(1) << endl;
    cout << endl;

    // Test case 3: x = 4
    cout << "Test case 3: x = 4" << endl;
    cout << "Expected: 2" << endl;
    cout << "Output: " << solution.mySqrt(4) << endl;
    cout << endl;

    // Test case 4: x = 8
    cout << "Test case 4: x = 8" << endl;
    cout << "Expected: 2" << endl;
    cout << "Output: " << solution.mySqrt(8) << endl;
    cout << endl;

    // Test case 5: x = 9
    cout << "Test case 5: x = 9" << endl;
    cout << "Expected: 3" << endl;
    cout << "Output: " << solution.mySqrt(9) << endl;
    cout << endl;

    // Test case 6: x = 16
    cout << "Test case 6: x = 16" << endl;
    cout << "Expected: 4" << endl;
    cout << "Output: " << solution.mySqrt(16) << endl;
    cout << endl;

    // Test case 7: x = 2147395599 (large number close to the maximum input)
    cout << "Test case 7: x = 2147395599" << endl;
    cout << "Expected: 46339" << endl;
    cout << "Output: " << solution.mySqrt(2147395599) << endl;
    cout << endl;

    // Test case 8: x = 2147483647 (maximum input value for a 32-bit integer)
    cout << "Test case 8: x = 2147483647" << endl;
    cout << "Expected: 46340" << endl;
    cout << "Output: " << solution.mySqrt(2147483647) << endl;
    cout << endl;

    return 0;
}
