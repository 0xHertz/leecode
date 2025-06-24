from typing_extensions import List
class Sulotion:
    def searchRange(self, nums:List[int], target:int) -> List[int]:
        left, right = 0, len(nums)-1
        while left <= right:
            middle = left + (right - left) // 2
            if (nums[middle] == target):
                if (nums[left] == target and nums[right] == target):
                    return [left,right]
                elif nums[left] < target:
                    left += 1
                elif nums[right] > target:
                    right -= 1
            elif (nums[middle] > target):
                right = middle - 1
            else:
                left = middle + 1
        return [-1,-1]
