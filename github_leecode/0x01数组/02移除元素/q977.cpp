/*
 *给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。
 * 输入：nums = [-4,-1,0,3,10]
 输出：[0,1,9,16,100]
 解释：平方后，数组变为 [16,1,0,9,100]
 排序后，数组变为 [0,1,9,16,100]
*/
#include <vector>
using namespace std;
class Solution{
    // 两种思路，先排序后平方，先平方后排序
    vector<int> sortedSquares(vector<int>& nums) {

    }
    // 双指针，相向指针
    vector<int> sortedSquares2(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        int i = 0, j = n-1;
        for (int ptr = n-1; ptr>=0; ptr--) {
            if (nums[i]*nums[i] > nums[j]*nums[j]) {
                result[ptr] = nums[i]*nums[i];
                i++;
            }else {
                result[ptr] = nums[j]*nums[j];
                j--;
            }
        }
        return result;
    }
};
