/*
二分查找
给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，
写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。


示例 1:
输入: nums = [-1,0,3,5,9,12], target = 9
输出: 4
解释: 9 出现在 nums 中并且下标为 4
*/
#include <vector>
using namespace std;
class Solution{
    public:
    // 会产生死循环，当数组中target不存在时，无法跳出循环
    int search(vector<int>& nums, int target){
        int left = 0;
        int right = nums.size();
        int middle = (right - left) / 2;
        while (nums[middle] != target) {
            if (nums[middle] > target) {
                left = middle;
            }else {
                right = middle;
            }
            middle = (right - left) / 2;
        }
        return middle;
    }
    int search2(vector<int> &nums, int target){
        int left = 0;
        // 注意这里的right应该是nums.size()-1，因为数组下标从0开始
        int right = nums.size()-1;
        int middle;
        while(left <= right){
            middle = left + (right - left) / 2;
            if (nums[middle] == target) {
                return middle;
            }else if (nums[middle] < target){
                left = middle + 1;
            }else {
                right = middle - 1;
            }
        };
        return -1;
    }
}
