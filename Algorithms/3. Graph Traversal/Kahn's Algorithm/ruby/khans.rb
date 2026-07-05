require '../Graphs/graph'

# Method 1
def topological_sort(nodes)
  stack = []
  result = []
  nodes.each { |node| stack.push(node) if node.in_edges.empty? }

  until stack.empty?
    node = stack.pop
    result.push(node)

    node.out_edges.dup.each do |edge|
      node = edge.to_vertex
      edge.destroy!
      stack.push(node) if node.in_edges.empty?
    end
  end
  result.length == nodes.length ? result : []
end


# Method 2
def topological_sort(nodes)
  queue = []
  sorted = []
  num_in_edges = Hash.new(0)
  nodes.each { |node| num_in_edges[node] = node.in_edges.length }
  nodes.each { |node| queue.push(node) if node.in_edges.empty? }

  until queue.empty?
    node = queue.shift
    sorted.push(node)

    node.out_edges.each do |edge|
      node = edge.to_vertex
      num_in_edges[node] -= 1
      if num_in_edges[node] == 0
        queue.push(node)
      end
    end
  end
  sorted.length == nodes.length ? sorted : []
end