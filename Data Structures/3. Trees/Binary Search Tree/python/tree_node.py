from __future__ import annotations

class TreeNode:

    left: TreeNode = None
    rite: TreeNode = None

    # O(1)
    def __init__(self, value: int):
        self.value = value

    # log(n)
    def insert_type_one(self, value: int) -> TreeNode:
        if self == None: return TreeNode(value)

        if value < self.value:
            self.left = self.left.insert(value)
        elif value > self.value:
            self.rite = self.rite.insert(value)
        
        return self
    
    # log(n)
    def insert_type_two(self, value: int) -> TreeNode:
        if value < self.value:
            if self.left:
                return self.left.insert(value)
            else:
                self.left = TreeNode(value)
                return self.left
        else:
            if self.rite:
                return self.rite.insert(value)
            else:
                self.rite = TreeNode(value)
                return self.rite

    def remove(self, value: int):
        if self == None: return

        if not self.left and not self.rite:
            return None
        elif not self.left:
            
            

        
