require_relative 'bst_node'

class BinarySearchTree
  attr_reader :root

  def initialize
    @root = nil
  end

  def insert(value)
    node = BSTNode.new(value)
    @root ? @root.append(node) : @root = node
    balance()
  end

  def delete(value)
    parent, target = search(value)

    if num_children(@root) == 0
      @root = nil

    elsif num_children(target) == 0
      parent.left = nil if target.value < parent.value
      parent.right = nil if target.value > parent.value
      
    elsif num_children(target) == 1
      parent.left = target.left || target.right if target.value < parent.value
      parent.right = target.left || target.right if target.value > parent.value

    elsif num_children(target) == 2
      proxy = maximum(target.left)
      delete(proxy.value)
      target.value < parent.value ? parent.left = proxy : parent.right = proxy
      proxy.left = target.left
      proxy.right = target.right
    end
    
    balance()
  end

  def find(value, node = @root)
    return nil unless node
    return node if node.value == value
    return value < node.value ? find(value, node.left) : find(value, node.right)
  end

  def balance
  end

  def maximum(node = @root)
    while node.right
      node = node.right
    end
    node
  end

  def depth(node = @root)
    return -1 unless node
    left = depth(node.left)
    rite = depth(node.right)
    return left >= rite ? left + 1 : rite + 1
  end 

  def is_balanced?(node = @root)
    return true unless node
    left = depth(node.left)
    rite = depth(node.right)
    is_depth = (left - rite).abs <= 1
    is_balan = is_balanced?(node.left) && is_balanced?(node.right)
    return is_depth && is_balan
  end

  def in_order_traversal(node = @root, arr = [])
    return arr unless node
    in_order_traversal(node.left, arr)
    arr.push(node.value)
    in_order_traversal(node.right, arr)
  end

  def pre_order_traversal(node = @root, arr = [])
    return arr unless node
    in_order_traversal(node.left, arr)
    in_order_traversal(node.right, arr)
    arr.push(node.value)
  end

  def post_order_traversal(node = @root, arr = [])
    return arr unless node
    arr.push(node.value)
    in_order_traversal(node.left, arr)
    in_order_traversal(node.right, arr)
  end

  private
  def search(value)
    parent = nil
    target = @root
    while target
      break if target.value == value
      parent = target
      target = value < target.value ? target.left : target.right
    end
    [parent, target]
  end

  def num_children(node)
    2 - [node.left, node.right].count(nil)
  end
end