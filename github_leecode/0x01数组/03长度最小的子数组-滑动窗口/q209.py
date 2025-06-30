from typing_extensions import List
class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        slow, sum, result = 0, 0, len(nums)+1
        for index,item in enumerate(nums):
            sum += item
            while sum >= target:
                result = result if result < (index-slow+1) else (index-slow+1)
                sum -= nums[slow]
                slow += 1
        return 0 if result == len(nums) + 1 else result
