class Solution:
    def targetIndices(self, nums: list[int], target: int) -> list[int]:
        res = []
        nums.sort()

        n = len(nums)
        l = 0
        r = n 
        first = -1
        while l < r:
            mid = l + (r - l) // 2

            if nums[mid] == target:
                first = mid
                r = mid
            elif nums[mid] > target:
                r = mid
            else: l = mid + 1

        if first == -1: return []

        l = 0 
        r = n
        last = -1
        while l < r:
            mid = l + (r - l) // 2

            if nums[mid] == target:
                last = mid
                l = mid + 1
            elif nums[mid] > target:
                r = mid
            else: l = mid + 1
        
        return list(range(first , last + 1)) 