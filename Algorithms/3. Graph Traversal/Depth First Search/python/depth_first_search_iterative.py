import sys
from pathlib import Path
sys.path.insert(0, str(Path(__file__).resolve().parents[4]/ "Data Structures" / "3. Trees" / "Binary Search Tree" / "python"))
from tree_node import TreeNode
        
# log(n)
def depth_first_search(root: TreeNode, value: int) -> TreeNode:
    node = root

    while node:
        if node.value < value:
            node = node.rite
        elif node.value > value:
            node = node.left
        else:
            return node
            
    return None
