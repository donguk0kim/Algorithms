import sys
from pathlib import Path
sys.path.insert(0, str(Path(__file__).resolve().parents[4]/ "Data Structures" / "3. Trees" / "Binary Search Tree" / "python"))
from tree_node import TreeNode

# log(n)
def breadth_first_search(root: TreeNode, value: int) -> TreeNode:
    if root.value == value: return root
    breadth_first_search(root.left, value)
