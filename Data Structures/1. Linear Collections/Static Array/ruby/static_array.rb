# This class just dumbs down a regular Array to be statically sized.
class StaticArray
  attr_reader :store

  def initialize(capacity)
    @capacity = capacity
    @store = Array.new(capacity)
  end

  # O(1)
  def [](index)
    check_index(index)
    @store[index]
  end

  # O(1)
  def []=(index, value)
    check_index(index)
    @store[index] = value
  end

  protected
  def check_index(index)
    raise 'index out of bounds' if index >= @capacity
  end
end