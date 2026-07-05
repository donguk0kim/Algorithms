class PolyTreeNode
  attr_reader :value, :parent, :children

  def initialize(value)
    @value = value
    @parent = nil
    @children = [];
  end

  def dfs(value)
    return self if self.value == value
    self.children.each do |child|
      node = child.dfs(value)
      return node if node
    end
    nil
  end
end