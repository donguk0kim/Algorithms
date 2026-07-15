import sys
from pathlib import Path
sys.path.insert(0, str(Path(__file__).resolve().parents[4]/ "Data Structures" / "3. Trees" / "Binary Search Tree" / "python"))
from tree_node import TreeNode
        
# log(n)
def depth_first_search(root: TreeNode, value: int) -> TreeNode:
    if not root: return None

    if root.value > value:
        return depth_first_search(root.left, value)
    elif root.value < value:
        return depth_first_search(root.rite, value)
    else:
        return root
    