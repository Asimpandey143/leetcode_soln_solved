import sys

# Increase recursion depth for deep trees
sys.setrecursionlimit(300000)

class Solution:
    def palindromePath(self, n: int, edges: list[list[int]], s: str, queries: list[str]) -> list[bool]:
        adj = [[] for _ in range(n)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)

        # Euler tour setup & Binary Lifting for LCA
        LOGN = 17
        up = [[0] * LOGN for _ in range(n)]
        depth = [0] * n
        tin = [0] * n
        tout = [0] * n
        timer = 0

        # Character mask array for each node
        val = [1 << (ord(ch) - ord('a')) for ch in s]

        # Root mask from root (node 0) to current node
        path_mask = [0] * n

        def dfs(u, p, d, current_xor):
            nonlocal timer
            timer += 1
            tin[u] = timer
            depth[u] = d
            path_mask[u] = current_xor ^ val[u]
            up[u][0] = p

            for i in range(1, LOGN):
                up[u][i] = up[up[u][i - 1]][i - 1]

            for v in adj[u]:
                if v != p:
                    dfs(v, u, d + 1, path_mask[u])

            tout[u] = timer

        dfs(0, 0, 0, 0)

        def get_lca(u, v):
            if depth[u] < depth[v]:
                u, v = v, u

            for i in range(LOGN - 1, -1, -1):
                if depth[u] - (1 << i) >= depth[v]:
                    u = up[u][i]

            if u == v:
                return u

            for i in range(LOGN - 1, -1, -1):
                if up[u][i] != up[v][i]:
                    u = up[u][i]
                    v = up[v][i]

            return up[u][0]

        # Fenwick Tree for Range XOR updates
        bit = [0] * (n + 2)

        def bit_update(idx, x):
            while idx <= n:
                bit[idx] ^= x
                idx += idx & (-idx)

        def bit_query(idx):
            res = 0
            while idx > 0:
                res ^= bit[idx]
                idx -= idx & (-idx)
            return res

        # Initialize BIT with base path masks
        for i in range(n):
            bit_update(tin[i], path_mask[i])
            bit_update(tin[i] + 1, path_mask[i])

        def get_node_path_mask(u):
            return bit_query(tin[u])

        ans = []

        for q in queries:
            parts = q.split()
            if parts[0] == "update":
                u = int(parts[1])
                c = parts[2]
                new_val = 1 << (ord(c) - ord('a'))
                diff = val[u] ^ new_val
                val[u] = new_val

                # Update path masks for u and all nodes in its subtree
                bit_update(tin[u], diff)
                bit_update(tout[u] + 1, diff)

            else:  # query u v
                u = int(parts[1])
                v = int(parts[2])
                lca = get_lca(u, v)

                # Path XOR = mask(u) ^ mask(v) ^ val(lca)
                path_xor = get_node_path_mask(u) ^ get_node_path_mask(v) ^ val[lca]

                # Check if at most 1 bit is set
                can_be_palindrome = (path_xor & (path_xor - 1)) == 0
                ans.append(can_be_palindrome)

        return ans