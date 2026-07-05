require '../Graphs/graph'

def topological_sort(nodes)
  result = []
  stack = Set.new
  visited = Set.new
  nodes.each do |node|
    unless visited.include?(node)
      cycle = visit(node, visited, stack, result)
      return [] if cycle
    end
  end
  result
end

def visit(node, visited, stack, result)
  stack.add(node)
  visited.add(node)
  node.out_edges.each do |edge|
    return true if stack.include?(edge.to_vertex)
    unless visited.include?(edge.to_vertex)
      cycle = visit(edge.to_vertex, visited, stack, result)
      return true if cycle
    end
  end
  stack.delete(node)
  result.unshift(node)
  return false
end
