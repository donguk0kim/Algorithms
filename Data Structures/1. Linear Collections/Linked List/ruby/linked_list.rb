class Node
  attr_accessor :key, :val, :next, :prev

  def initialize(key = nil, val = nil)
    @key = key
    @val = val
    @next = nil
    @prev = nil
  end

  def to_s
    "#{@key}: #{@val}"
  end

  # O(1)
  def remove
    prev_node = self.prev
    next_node = self.next
    prev_node.next = next_node
    next_node.prev = prev_node
  end
end

class LinkedList
  include Enumerable
  attr_reader :head, :tail

  def initialize
    @head = Node.new
    @tail = Node.new
    @head.next = @tail
    @tail.prev = @head
  end

  # O(n)
  def [](i)
    each_with_index { |node, index| return node if index == i }
  end

  # O(1)
  def first
    @head.next
  end

  # O(1)
  def last
    @tail.prev
  end

  # O(1)
  def empty?
    @head.next == @tail
  end

  # O(n)
  def get(key)
    each { |node| return node.val if node.key == key }
  end

  # O(n)
  def include?(key)
    each { |node| return true if node.key == key }
    false
  end

  # O(1)
  def append(key, val)
    node = Node.new(key, val)
    node.prev = last
    node.next = @tail
    last.next = node
    @tail.prev = node
    node
  end

  # O(n)
  def update(key, val)
    each do |node|
      if node.key == key
        node.val = val
        return node
      end
    end
  end

  # O(n)
  def remove(key)
    each do |node|
      if node.key == key
        node.remove
        return node
      end
    end
  end

  def each
    node = first
    until node == @tail
      yield node
      node = node.next
    end
  end

  # uncomment when you have `each` working and `Enumerable` included
  def to_s
    inject([]) { |acc, node| acc << "[#{node.key}, #{node.val}]" }.join(", ")
  end
end