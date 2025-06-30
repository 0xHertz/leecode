/*
给定一个含有 n 个正整数的数组和一个正整数 target 。
找出该数组中满足其总和大于等于 target 的长度最小的 子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。

输入：target = 7, nums = [2,3,1,2,4,3]
输出：2
解释：子数组 [4,3] 是该条件下的长度最小的子数组。
*/
#include <vector>
#include <cstdint>
#include <iostream>
using namespace std;
class Solution{
    public:
    // 暴力，双重循环
    int minSubArrayLen(int target, vector<int>& nums) {
        int length = nums.size();
        int result = INT32_MAX;
        int sum = 0, begin = 0;
        while (begin < length) {
            for (int index=begin; index<length; index++) {
                sum += nums[index];
            }
            if (sum < target) {
                begin++;
                length = nums.size();
            }else{
                result = (length-begin)>result ? result : length-begin;
                length--;
            }
            sum = 0;
        }
        return result == INT32_MAX ? 0 : result;
    }
    // 滑动窗口，用单重循环完成双重循环的功能，其本质上也是双指针法的一种
    int minSubArrayLen2(int target, vector<int>& nums) {
        int slow = 0,sum = 0;
        int result = INT32_MAX;
        for (int fast=0; fast<nums.size(); fast++) {
            sum += nums[fast];
            while (sum >= target) {
                result = result > (fast-slow+1) ? (fast-slow+1) : result;
                sum -= nums[slow];
                slow++;
            }
        }
        return result == INT32_MAX ? 0 : result;
    }
};

int main (int argc, char * argv[]){
    Solution app;
    vector<int> test = {2,3,1,2,4,3};
    cout << app.minSubArrayLen(7, test);
    cout << app.minSubArrayLen2(7, test);
    return 0;
}
