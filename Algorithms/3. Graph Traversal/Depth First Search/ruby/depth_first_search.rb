class PolyTreeNode
  attr_reader :value
  attr_reader :parent
  attr_reader :children

  def initialize (value)
    @value = value
    @parent = nil
    @children = []
  end

  def dfs (target_value)
    return self if @value == target_value
    @children.each do |child_node|
      target_node = child_node.dfs(target_value)
      return target_node if target_node
    end
    return nil
  end
end