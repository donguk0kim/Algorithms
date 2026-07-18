import sys
import unittest
from pathlib import Path

# Make backtracking.py and tree_node.py importable.
sys.path.insert(0, str(Path(__file__).resolve().parent))
sys.path.insert(0, str(Path(__file__).resolve().parents[3]
                       / "Data Structures" / "3. Trees"
                       / "Binary Search Tree" / "python"))

from tree_node import TreeNode
from backtracking import (
    has_path_to_leaf,
    path_to_leaf_type_one,
    path_to_leaf_type_two,
)


def build_tree() -> TreeNode:
    #    4
    #   / \
    #  0   1
    #   \ / \
    #   7 3  2
    #      \
    #       0
    #
    # Only 4 -> 1 -> 2 reaches a leaf without passing through a 0-valued node.
    root = TreeNode(4)
    root.left = TreeNode(0)
    root.rite = TreeNode(1)
    root.left.rite = TreeNode(7)
    root.rite.left = TreeNode(3)
    root.rite.rite = TreeNode(2)
    root.rite.left.rite = TreeNode(0)
    return root


class TestHasPathToLeaf(unittest.TestCase):
    def test_finds_path(self):
        self.assertTrue(has_path_to_leaf(build_tree()))

    def test_empty_tree(self):
        self.assertFalse(has_path_to_leaf(None))

    def test_zero_root_has_no_path(self):
        self.assertFalse(has_path_to_leaf(TreeNode(0)))

    def test_single_nonzero_leaf(self):
        self.assertTrue(has_path_to_leaf(TreeNode(5)))


class TestPathToLeafTypeOne(unittest.TestCase):
    def test_finds_path(self):
        path = []
        path_to_leaf_type_one(build_tree(), path)
        self.assertEqual(path, [4, 1, 2])

    def test_empty_tree(self):
        path = []
        self.assertFalse(path_to_leaf_type_one(None, path))
        self.assertEqual(path, [])


class TestPathToLeafTypeTwo(unittest.TestCase):
    def test_finds_path(self):
        # Pass an explicit list: the function's default arg is a shared
        # mutable list, so omitting it leaks state across calls.
        self.assertEqual(path_to_leaf_type_two(build_tree(), []), [4, 1, 2])

    def test_empty_tree(self):
        self.assertEqual(path_to_leaf_type_two(None, []), [])


if __name__ == "__main__":
    unittest.main()
