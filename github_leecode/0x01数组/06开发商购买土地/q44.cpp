/*
* 【题目描述】

在一个城市区域内，被划分成了n * m个连续的区块，每个区块都拥有不同的权值，代表着其土地价值。目前，有两家开发公司，A 公司和 B 公司，希望购买这个城市区域的土地。

现在，需要将这个城市区域的所有区块分配给 A 公司和 B 公司。

然而，由于城市规划的限制，只允许将区域按横向或纵向划分成两个子区域，而且每个子区域都必须包含一个或多个区块。

为了确保公平竞争，你需要找到一种分配方式，使得 A 公司和 B 公司各自的子区域内的土地总价值之差最小。

注意：区块不可再分。

【输入描述】

第一行输入两个正整数，代表 n 和 m。

接下来的 n 行，每行输出 m 个正整数。

输出描述

请输出一个整数，代表两个子区域内土地总价值之间的最小差距。

【输入示例】

3 3
1 2 3
2 1 3
1 2 3

【输出示例】
0

【提示】
如果将区域按照如下方式划分：

1 2 | 3
2 1 | 3
1 2 | 3

两个子区域内土地总价值之间的最小差距可以达到 0。

数据范围：

1 <= n, m <= 100；
n 和 m 不同时为 1
*/
#include <vector>
#include <iostream>
using namespace std;
class Solution{
    public:
    int buyLand(vector<vector<int>> land){
        // 两个循环，计算行向和纵向的区间和
        int i,j;
        int m = land.size(), n = m > 0 ? land[0].size() : 0;
        vector<int> rows_sum(m), cols_sum(n);
        int sum_row = 0, sum_col = 0;
        vector<int> result;
        int result_first, result_second;
        for (i=0; i<m; i++) {
            for (j=0; j<n; j++) {
                sum_row += land[i][j];
            }
            rows_sum[i] = sum_row;
        }

        for (j=0; j<n; j++) {
            for (i=0; i<m; i++) {
                sum_col += land[i][j];
            }
            cols_sum[j] = sum_col;
        }

        // 给定一个分界，计算差值，存贮到result，分界从0开始到m或n
        // 先计算行内差距
        for (int split=1; split<m; split++) {
            result_first = 0;
            result_second = 0;
            for (int left=0; left<split; left++) {
                result_first += rows_sum[left];
            }
            for (int right=split; right<m; right++) {
                result_second += rows_sum[right];
            }
            result.push_back(result_second - result_first >= 0 ? result_second - result_first : result_first - result_second);
        }
        // 再计算列内差距
        for (int split=1; split<n; split++) {
            result_first = 0;
            result_second = 0;
            for (int left=0; left<split; left++) {
                result_first += cols_sum[left];
            }
            for (int right=split; right<m; right++) {
                result_second += cols_sum[right];
            }
            result.push_back(result_second - result_first >= 0 ? result_second - result_first : result_first - result_second);
        }

        // 输出result中最小值
        int result_min = result[0];
        for (int item : result) {
            if (result_min > item) {
                result_min = item;
            }
        }
        return result_min;
    }
};

int main(int argc, char* argv[]){
    Solution app;
    vector<vector<int>> arr = {
        {1, 2, 3},
        {2, 1, 3},
        {1, 2, 3}
    };
    cout << app.buyLand(arr);
    return 0;
}
