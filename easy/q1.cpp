/*
给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案，并且你不能使用两次相同的元素。

你可以按任意顺序返回答案。
输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
*/
#include <algorithm>
#include <vector>
using namespace std;
class Solution{
    public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int one = 0;
        // 遍历
        for (auto item : nums) {
            // 找另一个
            auto other = find(nums.begin(),nums.end(),target-item);
            // 如果存在
            if (other != nums.end()){
                // 获取下标
                int index = std::distance(nums.begin(), other);
                // 等于当前元素下标
                if(index == one){
                    // 该元素不存在匹配，看下一个元素
                    ++one;
                    continue;
                }else{
                    // 返回结果
                    return vector<int>{index,one};
                }
            }
            ++one;
        }
        return vector<int>{};
    }
};
