class Solution:
    def missingMultiple(self, nums: list[int], k: int) -> int:
        lookup = set(nums)
        mult = k
        while mult in lookup:
            mult += k
        return mult