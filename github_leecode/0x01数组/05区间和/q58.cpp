/*
给定一个整数数组 Array，请计算该数组在每个指定区间内元素的总和。

第一行输入为整数数组 Array 的长度 n，接下来 n 行，每行一个整数，表示数组的元素。随后的输入为需要计算总和的区间下标：a，b （b > = a），直至文件结束。

5
1
2
3
4
5
0 1
1 3

3
9
*/

#include <vector>
#include <iostream>
using namespace std;
class Solution{
    public:
    // 这不就直接遍历区间求和, 最后复杂度超了
    int rangeSum(vector<int> arr, int a, int b){
        int sum = 0;
        for (int i=a; i<=b; i++) {
            sum += arr[i];
        }
        return sum;
    }
    // 前缀和,见main函数

};

int main(int argc, char* argv[]){
    int len = 0;
    cin >> len;

    vector<int> arr(len);
    vector<int> psum(len);
    int psumtmp = 0;
    for(auto i = 0; i<len; i++){
        cin >> arr[i];
        psumtmp += arr[i];
        psum[i] = psumtmp;

    }
    int begin,end;
    Solution app;
    while (cin >> begin >> end) {
        // 暴力求和
        cout << app.rangeSum(arr, begin, end) << endl;
        // 前缀和
        cout << "-----------------" << endl;
        if (begin == 0) {
            cout << psum[end];
        }else{
            cout << psum[end] - psum[begin];
        }
    }
    return 0;
}
