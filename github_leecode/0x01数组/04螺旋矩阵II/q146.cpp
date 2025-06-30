/*
* 给定一个二维数组 array，请返回「螺旋遍历」该数组的结果。
* 螺旋遍历：从左上角开始，按照 向右、向下、向左、向上 的顺序 依次 提取元素，然后再进入内部一层重复相同的步骤，直到提取完所有元素。
*/

#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

class Solution{
    public:
    vector<int> spiralArray(vector<vector<int>>& array) {
        int m = array.size(), n = m > 0 ? array[0].size() : 0;

        vector<int> result;

        int startx = 0, starty = 0;
        int loop = min(m, n) / 2;
        int leave = min(m, n) - loop*2 >= 1 ? max(m, n)-loop*2 : 0;
        int offset = 1;
        int i, j;
        while (loop--) {
            i = startx;
            j = starty;
            for (; j<n-offset; j++) {
                result.push_back(array[i][j]);
            }
            for (; i<m-offset; i++) {
                result.push_back(array[i][j]);
            }
            for (; j > starty; j--) {
                result.push_back(array[i][j]);
            }
            for (; i > startx; i--) {
                result.push_back(array[i][j]);
            }
            startx++;
            starty++;
            offset++;
        }
        if (m>n) {
            while (leave--) {
                result.push_back(array[startx++][starty]);
            }
        }else if (n > m) {
            while (leave--) {
                result.push_back(array[startx][starty++]);
            }
        }else{
            while (leave--) {
                result.push_back((array[m/2][n/2]));
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
    vector<int> res = app.spiralArray(arr);
    for (auto item : res) {
            cout << item;
    }
    return 0;
}
