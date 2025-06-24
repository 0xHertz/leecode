/*
给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。

请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。

注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。为了应对这种情况，nums1 的初始长度为 m + n，其中前 m 个元素表示应合并的元素，
后 n 个元素为 0 ，应忽略。nums2 的长度为 n 。

输入：nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
输出：[1,2,2,3,5,6]
*/
#include <vector>
#include <iostream>
using namespace std;

void printVector(const vector<int>& vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

class Solution {
public:
    // 先找位置再插入
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        bool flag = false;
        for (int i = 0; i<n; i++){
            flag = false;
            // 还可以优化，不从0开始，而是从上次插入位置开始
            for(int j=0; j<m+i; j++){
                if (nums2[i] > nums1[j] && nums2[i]<=nums1[j+1]){
                    flag = true;
                    putItem(nums1, nums2[i], j+1,m+i);
                    break;
                }
            }
            if (flag){
                continue;
            }else if (nums2[i] <= nums1[0]){
                putItem(nums1, nums2[i], 0, m+i);
            }else{
                putItem(nums1, nums2[i], m+i, m+i);
            }
        }
    }
    void putItem(vector<int>& nums1,int val,int index,int m){
        for(int i = m;i>index;i--){
            nums1[i] = nums1[i-1];
        }
        nums1[index] = val;
        printVector(nums1);
    }
};

int main() {
    Solution solution;

    // 测试用例 1
    vector<int> nums1_1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2_1 = {2, 5, 6};
    solution.merge(nums1_1, 3, nums2_1, 3);
    // printVector(nums1_1); // 输出: [1, 2, 2, 3, 5, 6]

    // 测试用例 2
    vector<int> nums1_2 = {1, 0};
    vector<int> nums2_2 = {2};
    solution.merge(nums1_2, 1, nums2_2, 1);
    // printVector(nums1_2); // 输出: [1, 2]

    // 测试用例 3
    vector<int> nums1_3 = {0};
    vector<int> nums2_3 = {1};
    solution.merge(nums1_3, 0, nums2_3, 1);
    // printVector(nums1_3); // 输出: [1]

    // 测试用例 4
    vector<int> nums1_4 = {4, 5, 6, 0, 0, 0};
    vector<int> nums2_4 = {1, 2, 3};
    solution.merge(nums1_4, 3, nums2_4, 3);
    // printVector(nums1_4); // 输出: [1, 2, 3, 4, 5, 6]

    // 测试用例 5
    vector<int> nums1_5 = {-1,-1,0,0,0,0};
    vector<int> nums2_5 = {-1,0};
    solution.merge(nums1_5, 5, nums2_5, 1);
    // printVector(nums1_5); // 输出: [1, 2, 3, 4, 5, 6]

    return 0;
}
