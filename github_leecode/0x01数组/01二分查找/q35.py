from typing_extensions import List
class Solution:
    def searchInsert(self, nums:List[int], target:int) -> int:
        left, right = 0, len(nums)-1
        while left <= right:
            middle = left + (right - left) // 2
            if (nums[middle] == target):
                return middle
            elif (nums[middle] > target):
                right = middle - 1
            else:
                left = middle + 1
        return left
