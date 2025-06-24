/*
给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。

你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。

返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。

输入：[7,1,5,3,6,4]
输出：5
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution{
    public:
    // 这种逻辑是错误的[2,4,1]
    int maxProfit(vector<int>& prices) {
        // 简化为数组元素最大差值
        // 选中最小值
        auto min = min_element(prices.begin(),prices.end());
        int min_index = distance(prices.begin(), min);
        // 依次选中最大值，如果最大值索引小于最小值，剔除该最大值，直到最大值索引大于最小值
        while (true) {
            auto max_it = max_element(prices.begin(), prices.end());
            int max_index = distance(prices.begin(), max_it);

            if (max_index > min_index) {
                return *max_it - *min;
            } else {
                prices.erase(max_it);
            }

            if (prices.empty()) {
                return 0;
            }
        }
    }
};
int main() {
    Solution solution;
    // 测试用例 1
    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    cout << "Test Case 1: " << endl;
    cout << "Input: [7, 1, 5, 3, 6, 4]" << endl;
    cout << "Output: " << solution.maxProfit(prices1) << endl; // Expected output: 5

    // 测试用例 2
    vector<int> prices2 = {7, 6, 4, 3, 1};
    cout << "Test Case 2: " << endl;
    cout << "Input: [7, 6, 4, 3, 1]" << endl;
    cout << "Output: " << solution.maxProfit(prices2) << endl; // Expected output: 0

    // 测试用例 3
    vector<int> prices3 = {1, 2, 3, 4, 5};
    cout << "Test Case 3: " << endl;
    cout << "Input: [1, 2, 3, 4, 5]" << endl;
    cout << "Output: " << solution.maxProfit(prices3) << endl; // Expected output: 4

    // 测试用例 4
    vector<int> prices4 = {2, 4, 1};
    cout << "Test Case 4: " << endl;
    cout << "Input: [2, 4, 1]" << endl;
    cout << "Output: " << solution.maxProfit(prices4) << endl; // Expected output: 2

    return 0;
}
