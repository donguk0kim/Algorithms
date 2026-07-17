from tree_node import TreeNode

# log(n)
def insert(root: TreeNode, value: int) -> TreeNode:
    if root == None: return TreeNode(value)

    if value < root.value:
        root.left = insert(root.left, value)
    elif value > root.value:
        root.rite = insert(root.rite, value)

    return root

# log(n)
def remove(root: TreeNode, value: int) -> TreeNode:
    if value < root.value:
        root.left = remove(root.left, value)
    elif value > root.value:
        root.rite = remove(root.rite, value)
    else:
        if not root.left and not root.rite:
            return None
        elif not root.left:
            return root.rite
        elif not root.rite:
            return root.left
        else:
            min = findMin(root.rite)
            min.rite = remove(root.rite, min.value)
            min.left = root.left
            return min
    
    return root

def findMin(root: TreeNode) -> TreeNode:
    node = root
    while node.left:
        node = node.left
    return node

# create tree
values = [5, 3, 7, 1, 4, 9, 0, 2, 10]
root = TreeNode(values[0])
for value in values[1:]:
    insert(root, value)

# insert test case
print("insert test case")
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

# remove test case
print("remove test case")
root = remove(root, 2)
print(root.left.left.rite == None)
root = remove(root, 3)
print(root.left.value == 4)
print(root.left.left.value == 1)
root = remove(root, 5)
print(root.value == 7)
print(root.left.value == 4)
print(root.rite.value == 9)
root = remove(root, 7)
print(root.value == 9)
print(root.left.value == 4)
print(root.rite.value == 10)
print("")
