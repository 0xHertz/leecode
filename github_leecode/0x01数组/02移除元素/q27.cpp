/*
给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。

不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并原地修改输入数组。

元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

示例 1: 给定 nums = [3,2,2,3], val = 3, 函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。 你不需要考虑数组中超出新长度后面的元素。

示例 2: 给定 nums = [0,1,2,2,3,0,4,2], val = 2, 函数应该返回新的长度 5, 并且 nums 中的前五个元素为 0, 1, 3, 0, 4。
*/
#include <vector>
using namespace std;
class Solution{
    // 遍历，双重循环,O(n^2)
    int removeElement(vector<int>& nums, int val) {
        int numbers = 0;
        for (auto i = 0; i<nums.size() - numbers; i++) {
            if (nums[i] == val) {
                ++numbers;
                for (auto index=i; index<nums.size()-1; index++) {
                    nums[index] = nums[index+1];
                }
                i--;
            }
        }
        return nums.size()-numbers;
    }
    // 遍历，单重循环,O(n),恍然大悟，就是快慢指针
    int removeItem(vector<int> &nums, int val){
        int result = 0;
        for (int item : nums) {
            if (item != val) {
                // 不相等时，更新结果
                nums[result++] = item;
            }
        }
        return result;
    }
    // 快慢指针，单重循环完成双循环的工作，快指针：寻找新数组的元素 ，新数组就是不含有目标元素的数组，慢指针：指向更新 新数组下标的位置
    int removeItem2(vector<int> &nums, int val){
        int slow = 0;
        for (int i; i<nums.size(); i++) {
            if (nums[i] != val) {
                // 更新结果
                nums[slow++] = nums[i];
            }
        }
        return slow;
    }
};
