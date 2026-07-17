from tree_node import TreeNode

# create tree
values = [5, 3, 7, 1, 4, 9, 0, 2, 10]
root = TreeNode(values[0])
for value in values[1:]:
    root.insert(value)

# TreeNode::insert
print("TreeNode::insert")
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

# TreeNode::remove
print("TreeNode::remove")
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
