/*
* 给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。
*/

#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
class Solution{
    public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int startx=0, starty=0;
        int m = matrix.size(), n = m > 0 ? matrix[0].size() : 0;
        int loop = min(m/2,n/2);
        int offset = 1;
        int leave = min(m,n)-loop*2 >= 1 ? max(m,n)-loop*2 : 0;
        int i,j;
        while (loop--) {
            i = startx;
            j = starty;
            for (; j < n-offset; j++) {
                result.push_back(matrix[i][j]);
            }

            for (; i < m-offset; i++) {
                result.push_back(matrix[i][j]);
            }

            for (; j > starty; j--) {
                result.push_back(matrix[i][j]);
            }

            for (; i > startx; i--) {
                result.push_back(matrix[i][j]);
            }
            startx++;
            starty++;

            offset++;
        }
        if (m > n) {
            while (leave--) {
                result.push_back(matrix[startx++][starty]);
            }
        }else if (m < n) {
            while (leave--) {
                result.push_back(matrix[startx][starty++]);
            }
        }else{
            while (leave--) {
                result.push_back(matrix[m/2][n/2]);
            }
        }
        return result;
    }
};

int main(int argc, char* argv[]){
    Solution app;
    vector<vector<int>> arr = {
            {1}
        };
    vector<int> res = app.spiralOrder(arr);
    for (auto item : res) {
            cout << item;
    }
    return 0;
}
