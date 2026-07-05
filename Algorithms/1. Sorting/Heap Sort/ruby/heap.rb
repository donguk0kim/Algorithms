require 'byebug'

class BinaryMinHeap
  attr_reader :store

  def initialize(&prc)
    @store = []
    @prc = prc
  end

  def count
    @store.length
  end

  def empty?
    count == 0
  end

  def extract
    @store[0], @store[-1] = @store[-1], @store[0]
    root_value = @store.pop
    BinaryMinHeap.heapify_down(@store, 0, count, &@prc)
    root_value
  end

  def peek
    @store.first
  end

  def push(val)
    @store.push(val)
    BinaryMinHeap.heapify_up(@store, count - 1, count, &@prc)
  end

  public

  def self.child_indices(length, p_idx)
    child_indices = []
    left_index = 2 * p_idx + 1
    rite_index = 2 * p_idx + 2
    child_indices.push(left_index) if left_index < length
    child_indices.push(rite_index) if rite_index < length
    child_indices
  end

  def self.parent_index(child_index)
    p_idx = (child_index - 1) / 2
    raise 'root has no parent' if p_idx < 0
    p_idx
  end

  def self.index_of_smaller(array, child_indices, &prc)
    if child_indices.length == 0
      min_index = nil
    end

    if child_indices.length == 1
      min_index = child_indices[0]
    end

    if child_indices.length == 2
      left = array[child_indices[0]]
      rite = array[child_indices[1]]
      min_index = prc.call(left, rite) == -1 ? child_indices[0] : child_indices[1]
    end

    min_index
  end

  def self.heapify_down(array, p_idx, length = array.length, &prc)
    prc = prc || Proc.new { |node1, node2| node1 <=> node2 }
    child_indices = self.child_indices(length, p_idx)
    min_index = self.index_of_smaller(array, child_indices, &prc)
    return array if min_index == nil

    parent, child = array[p_idx], array[min_index]
    array[p_idx], array[min_index] = child, parent if prc.call(parent, child) == 1
    self.heapify_down(array, min_index, length, &prc)
  end

  def self.heapify_up(array, c_idx, length = array.length, &prc)
    prc = prc || Proc.new { |node1, node2| node1 <=> node2 }
    return array if c_idx == 0

    p_idx = self.parent_index(c_idx)
    parent, child = array[p_idx], array[c_idx]

    array[p_idx], array[c_idx] = child, parent if prc.call(parent, child) == 1
    self.heapify_up(array, p_idx, length, &prc)
  end
end