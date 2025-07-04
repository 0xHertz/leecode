/*
给你一个正整数 num 。如果 num 是一个完全平方数，则返回 true ，否则返回 false 。

完全平方数 是一个可以写成某个整数的平方的整数。换句话说，它可以写成某个整数和自身的乘积。

不能使用任何内置的库函数，如  sqrt 。
 */
class Solution{
    bool isPerfectSquare(int num) {
        int left = 0;
        int right = num;
        int mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if ((long long)mid*mid == num) {
                return true;
            }else if((long long)mid * mid < num) {
                left = mid + 1;
            }else {
                right = mid - 1;
            }
        }
        return false;
    }
};
