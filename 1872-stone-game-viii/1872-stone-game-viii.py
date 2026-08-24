from itertools import accumulate
from typing import List

class Solution:
    def stoneGameVIII(self, stones: List[int]) -> int:
        prefix = list(accumulate(stones))
        n = len(stones)
        
        # Base case: Alice/Bob must take all remaining stones if they choose the last index
        # dp stores the best value obtainable from suffix [i ... n-1]
        dp = prefix[-1]
        
        # Iterate backwards from n - 2 down to 1 (since x >= 2 stones must be picked initially)
        for i in range(n - 2, 0, -1):
            dp = max(dp, prefix[i] - dp)
            
        return dp