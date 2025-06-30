/*
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

请注意 ，必须在不复制数组的情况下原地对数组进行操作。

示例 1:

输入: nums = [0,1,0,3,12]
输出: [1,3,12,0,0]
*/
#include <vector>
using namespace std;

class Solution{
    // 我直接快慢指针
    void moveZeroes(vector<int>& nums) {
        int result = 0;
        for (int item : nums) {
            if (item != 0) {
                nums[result++] = item;
            }
        }// [1,3,12,3,12]
        for (int i=result; i<nums.size(); i++) {
            nums[i] = 0;
        }
    }
};
