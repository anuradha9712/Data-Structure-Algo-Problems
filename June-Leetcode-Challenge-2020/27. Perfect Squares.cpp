/*
27. Perfect Squares

Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

Example 1:

Input: n = 12
Output: 3 
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
*/

# O(sqrt(n)) time complexity
#  Lagrange’s four-square theorem 
class Solution:
    def is_perfect(self, n):
        x = int(math.sqrt(n))
        return x * x == n

    def numSquares(self, n: int) -> int:
        if n < 4:
            return n

        if self.is_perfect(n):  # number is a perfect square
            return 1

        # the result is 4 if number = 4^k*(8*m + 7)
        while n & 3 == 0:  # while divisible by 4
            n >>= 2
        if n & 7 == 7:  # 8m+7 => last 3 digits = 111
            return 4

        x = int(math.sqrt(n))
        for i in range(1, x + 1):  # sum of 2 perfect squares
            if self.is_perfect(n - i * i):
                return 2

        return 3  # by elimination
