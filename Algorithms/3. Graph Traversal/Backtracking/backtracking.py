import sys
from pathlib import Path
sys.path.insert(0, str(Path(__file__).resolve().parents[3]/ "Data Structures" / "3. Trees" / "Binary Search Tree" / "python"))
from tree_node import TreeNode

# O(n)
def has_path_to_leaf(root: TreeNode) -> bool:
    if not root:
        return False
    if root.value == 0:
        return False

    if not root.left and not root.rite:
        return True
    if has_path_to_leaf(root.left):
        return True
    if has_path_to_leaf(root.rite):
        return True
    
    return False

# O(n)
def path_to_leaf_type_one(root: TreeNode, path: list[TreeNode]) -> bool:
    if not root:
        return False
    if root.value == 0:
        return False
    else:
        path.append(root.value)

    if not root.left and not root.rite:
        return True
    else:
        if path_to_leaf_type_one(root.left, path):
            return True
        if path_to_leaf_type_one(root.rite, path):
            return True
    
    path.pop()
    
    return False

# O(n)
def path_to_leaf_type_two(root: TreeNode, path: list[int] = []) -> list[int]:
    if not root:
        return []
    if root.value == 0:
        return []
    else:
        path.append(root.value)

    if not root.left and not root.rite:
        return path
    else:
        if left := path_to_leaf_type_two(root.left, path):
            path = left
        if rite := path_to_leaf_type_two(root.rite, path):
            path = rite
        if not left and not rite:
            path.pop()

    return path
