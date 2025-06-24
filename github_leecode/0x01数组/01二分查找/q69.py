class Solution:
    def mySqrt(self,x:int)->int:
        left, right, result = 0,x,0;
        while left <= right:
            middle = left + (right - left) // 2
            if middle*middle <= x:
                result = middle
                left = middle + 1
            else:
                right = middle - 1
        return result
