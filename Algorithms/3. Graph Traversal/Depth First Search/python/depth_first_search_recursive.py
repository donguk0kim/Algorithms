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
    
#      4
#     / \
#    3   6
#   /   / \
#  2   5   7
    
# O(n)  2 -> 3 -> 4 -> 5 -> 6 -> 7
def in_order_traversal(root: TreeNode):
    if not root: return
    in_order_traversal(root.left)
    print(root.value)
    in_order_traversal(root.rite)

# O(n)  4 -> 3 -> 2 -> 6 -> 5 -> 7
def pre_order_traversal(root: TreeNode):
    if not root: return
    print(root.value)
    pre_order_traversal(root.left)
    pre_order_traversal(root.rite)


# O(n)  2 -> 3 -> 5 -> 7 -> 6 -> 4
def post_order_traversal(root: TreeNode):
    if not root: return
    post_order_traversal(root.left)
    post_order_traversal(root.rite)
    print(root.value)
