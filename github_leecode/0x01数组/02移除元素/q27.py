from typing_extensions import List


class Solution:
    def removeElement(self, nums:List, val:int) -> int:
        result = 0;
        for item in nums:
            if item is not val:
                nums[result] = item
                result += 1
        return result
    def testRange(self):
        for i in range(0,8):
            print(i)

if __name__ == "__main__":
    app = Solution();
    # app.testRange();
    app.removeElement([3,2,2,3],3)
