import sys

# It's good practice to increase the recursion limit for deep trees.
sys.setrecursionlimit(200005)

def solve():
    """
    Reads graph input, runs the solution, and prints the result.
    """
    try:
        n_str = sys.stdin.readline()
        if not n_str: return
        n = int(n_str)

        adj = [[] for _ in range(n + 1)]
        for _ in range(n - 1):
            u, v = map(int, sys.stdin.readline().split())
            adj[u].append(v)
            adj[v].append(u)

    except (IOError, ValueError):
        return

    # This array will store the size of the subtree for each node.
    subtree_size = [0] * (n + 1)

    # 1. First DFS: Calculate the size of each subtree.
    def calculate_sizes(u, p):
        """
        Calculates subtree sizes via a post-order traversal.
        """
        size = 1
        for v in adj[u]:
            if v != p:
                size += calculate_sizes(v, u)
        subtree_size[u] = size
        return size

    calculate_sizes(1, 0)

    # State for the simulation
    alice_score = 0
    turn_counter = 0

    # 2. Second DFS: Simulate the game turn by turn.
    def simulate_game(u, p):
        """
        Simulates the game traversal, updating scores based on turn order.
        """
        nonlocal alice_score, turn_counter

        # A. Collect the coin at the current node 'u'.
        # Alice collects on even turns (0, 2, 4...).
        if turn_counter % 2 == 0:
            alice_score += 1
        turn_counter += 1

        # B. Get children and sort them by their subtree size.
        children = []
        for v in adj[u]:
            if v != p:
                children.append(v)
        
        # The optimal strategy is to always visit the smallest subtree next.
        children.sort(key=lambda v: subtree_size[v])

        # C. Visit each child according to the optimal order.
        for v in children:
            # Move u -> v
            turn_counter += 1
            simulate_game(v, u)
            # Move v -> u
            turn_counter += 1

    simulate_game(1, 0)
    print(alice_score)

# Run the solution
solve()