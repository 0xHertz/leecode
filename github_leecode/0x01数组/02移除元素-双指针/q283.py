from typing_extensions import List
class Solution:
    def moveZeroes(self, nums:List):
        result = 0
        for item in nums:
            if item is not 0:
                nums[result] = item
                result += 1
        for i in range(result,len(nums)):
            nums[i] = 0
