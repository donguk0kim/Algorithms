from __future__ import annotations

class TreeNode:

    left: TreeNode = None
    rite: TreeNode = None

    # O(1)
    def __init__(self, value: int) -> TreeNode:
        self.value = value

    # log(n)
    def insert(self, value: int) -> TreeNode:
        if value < self.value:
            if self.left:
                return self.left.insert(value)
            else:
                self.left = TreeNode(value)
                return self.left
        elif value > self.value:
            if self.rite:
                return self.rite.insert(value)
            else:
                self.rite = TreeNode(value)
                return self.rite
            
    def insert_type_two(self, value: int) -> TreeNode:
        if self == None: return TreeNode(value)

        if value < self.value:
            self.left = self.left.insert(value)
        elif value > self.value:
            self.rite = self.rite.insert(value)

        return self

    # log(n)
    def remove(self, value: int) -> TreeNode:
        if value < self.value:
            self.left = self.left.remove(value)
        elif value > self.value:
            self.rite = self.rite.remove(value)
        else:
            if not self.left and not self.rite:
                return None
            elif not self.left:
                return self.rite
            elif not self.rite:
                return self.left
            else:
                min = self.rite.findMin()
                min.rite = self.rite.remove(min.value)
                min.left = self.left
                return min

        return self
    
    # log(n)
    def findMin(self) -> TreeNode:
        node = self
        while node.left:
            node = node.left
        return node


# create tree
values = [5, 3, 7, 1, 4, 9, 0, 2, 10]
root = TreeNode(values[0])
for value in values[1:]:
    root.insert_type_two(value)

# TreeNode::insert test case
print("TreeNode::insert test case")
print(root.value == 5)
print(root.left.value == 3)
print(root.left.left.value == 1)
print(root.left.left.left.value == 0)
print(root.left.left.rite.value == 2)
print(root.left.rite.value == 4)
print(root.rite.value == 7)
print(root.rite.rite.value == 9)
print(root.rite.rite.rite.value == 10)
print("")

# TreeNode::remove test case
print("TreeNode::remove test case")
root = root.remove(2)
print(root.left.left.rite == None)
root = root.remove(3)
print(root.left.value == 4)
print(root.left.left.value == 1)
root = root.remove(5)
print(root.value == 7)
print(root.left.value == 4)
print(root.rite.value == 9)
root = root.remove(7)
print(root.value == 9)
print(root.left.value == 4)
print(root.rite.value == 10)
print("")
