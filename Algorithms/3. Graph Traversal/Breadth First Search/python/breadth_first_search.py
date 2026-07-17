import sys
from pathlib import Path
sys.path.insert(0, str(Path(__file__).resolve().parents[4]/ "Data Structures" / "3. Trees" / "Binary Search Tree" / "python"))
from tree_node import TreeNode
from collections import deque

# log(n)
def breadth_first_search(root: TreeNode, value: int) -> TreeNode:
    queue = deque([root])

    while queue:
        node = queue.popleft()
        if node.value == value: return node
        if node.left != None: queue.append(node.left)
        if node.rite != None: queue.append(node.rite)

    return None
