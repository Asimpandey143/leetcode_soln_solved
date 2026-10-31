class Solution:
    def uniquePaths(self, grid: List[List[int]]) -> int:
        MOD = 10**9 + 7
        m, n = len(grid), len(grid[0])
        
        # Precompute destination for each cell and direction
        # jump[r][c][0] -> destination cell (nr, nc) when attempting to move RIGHT from (r, c)
        # jump[r][c][1] -> destination cell (nr, nc) when attempting to move DOWN from (r, c)
        jump = [[ [None, None] for _ in range(n) ] for _ in range(m)]
        
        # Fill from bottom-right to top-left for DP-like precomputation
        for r in range(m - 1, -1, -1):
            for c in range(n - 1, -1, -1):
                # 1. Moving Right from (r, c) target cell is (r, c + 1)
                nr, nc = r, c + 1
                if nr < m and nc < n:
                    if grid[nr][nc] == 0:
                        jump[r][c][0] = (nr, nc)
                    else:
                        # Mirror encountered moving right -> redirects down to (nr + 1, nc)
                        # which is equivalent to moving DOWN from (nr, nc)
                        jump[r][c][0] = jump[nr][nc][1]
                
                # 2. Moving Down from (r, c) target cell is (r + 1, c)
                nr, nc = r + 1, c
                if nr < m and nc < n:
                    if grid[nr][nc] == 0:
                        jump[r][c][1] = (nr, nc)
                    else:
                        # Mirror encountered moving down -> redirects right to (nr, nc + 1)
                        # which is equivalent to moving RIGHT from (nr, nc)
                        jump[r][c][1] = jump[nr][nc][0]

        # DP array to store unique path counts
        dp = [[0] * n for _ in range(m)]
        dp[0][0] = 1
        
        for r in range(m):
            for c in range(n):
                if dp[r][c] == 0:
                    continue
                
                val = dp[r][c]
                
                # Try moving Right
                dest_right = jump[r][c][0]
                if dest_right:
                    nr, nc = dest_right
                    dp[nr][nc] = (dp[nr][nc] + val) % MOD
                
                # Try moving Down
                dest_down = jump[r][c][1]
                if dest_down:
                    nr, nc = dest_down
                    dp[nr][nc] = (dp[nr][nc] + val) % MOD
                    
        return dp[m - 1][n - 1]