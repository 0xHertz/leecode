class Solution:
    def backspaceCompare(self,s,t) -> bool:
        res1,res2 = 0,0
        for char in s:
            if char != "#":
                s[res1] = char # 由于python中str类型是静态的，不能直接修改，因此这句错误
                res1 += 1
            else:
                res1 = res1-1 if res1>=1 else 0

        for char in t:
            if char != "#":
                t[res2] = char
                res2 += 1
            else:
                res2 = res2-1 if res2>=1 else 0
        if res1 is not res2:
            return False
        for i in range(0,res1):
            if s[i] is not t[i]:
                return False
        return True
