class BSTNode
  attr_reader :value
  attr_accessor :left
  attr_accessor :right

  def initialize(value)
    @left = nil
    @right = nil
    @value = value
  end

  def append(node)
    if node.value <= self.value
      self.left ? self.left.append(node) : self.left = node
    else
      self.right ? self.right.append(node) : self.right = node
    end
  end
end