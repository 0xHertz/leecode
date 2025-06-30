from typing_extensions import List
class Solution:
    def removeDuplicates(self,nums:List) -> int :
        result = 0
        for item in nums:
            if item > nums[result]:
                result += 1
                nums[result] = item;
        return result+1
