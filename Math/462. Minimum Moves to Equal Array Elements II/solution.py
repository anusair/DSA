class Solution:
    def minMoves2(self, nums: list[int]) -> int:
        nums.sort()
        n = len(nums)
        sm = nums[n // 2]

        res = 0
        for i in range(n):
            res += abs(nums[i] - sm)
        
        return res