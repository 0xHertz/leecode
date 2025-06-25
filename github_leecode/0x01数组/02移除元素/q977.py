from typing_extensions import List
class Solution:
    def sortedSquares(self, nums:List) -> List:
        i,j = 0,len(nums)-1
        result = []
        for p in range(len(nums)-1,-1,-1):
            if nums[i]*nums[i] > nums[j]*nums[j]:
                result.insert(0,nums[i]*nums[i])
                i += 1
            else:
                result.insert(0,nums[j]*nums[j])
                j -= 1
        return result

if __name__ == "__main__":
    app = Solution()
    app.sortedSquares([-4,-1,0,3,10])
