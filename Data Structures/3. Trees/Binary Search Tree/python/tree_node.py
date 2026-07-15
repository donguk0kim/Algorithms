from __future__ import annotations

class TreeNode:

    left: TreeNode = None
    rite: TreeNode = None

    # O(1)
    def __init__(self, value: int) -> TreeNode:
        self.value = value

    # log(n)
    def insert(self, value: int) -> TreeNode:
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

        

            

        
