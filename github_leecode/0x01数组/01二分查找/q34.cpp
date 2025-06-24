/*
 给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

 如果数组中不存在目标值 target，返回 [-1, -1]。

 进阶：你可以设计并实现时间复杂度为 $O(\log n)$ 的算法解决此问题吗？

 示例 1：

 输入：nums = [5,7,7,8,8,10], target = 8
 输出：[3,4]
 示例 2：

 输入：nums = [5,7,7,8,8,10], target = 6
 输出：[-1,-1]
 */
#include <vector>
using namespace std;
class Solution{
    public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int middle;
        while (left <= right) {
            middle = left + (right -left) / 2;
            if (nums[middle] == target) {
                if (nums[left] == target && nums[right] == target) {
                    return vector{left,right};
                }else if (nums[left] < target){
                    ++left;
                }else if (nums[right] > target) {
                    --right;
                }
            }else if (nums[middle] > target) {
                right = middle - 1;
            }else {
                left = middle + 1;
            }
        }
        return vector{-1,-1};
    }
}
