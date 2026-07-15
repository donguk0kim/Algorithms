from tree_node import TreeNode
import sys
from pathlib import Path
sys.path.insert(0, str(Path(__file__).resolve().parents[4]/ "Algorithms" / "3. Graph Traversal" / "Depth First Search" / "python"))
from depth_first_search_iterative import depth_first_search

class BinarySearchTree:
    
    root: TreeNode = None

    # O(1)
    def __init__(self, root: TreeNode = None) -> BinarySearchTree:
        pass

    # log(n)
    def insert(self, value: int) -> TreeNode:
        return self.root.insert(value)

    # log(n)
    def remove(self, value: int):
        node = self.find(value)
        
    # log(n)
    def find(self, value: int) -> TreeNode:
        return depth_first_search(self.root, value)
