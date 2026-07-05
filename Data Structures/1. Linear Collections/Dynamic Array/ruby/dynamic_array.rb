require_relative 'static_array'

class DynamicArray
  attr_reader :length, :capacity, :store

  def initialize
    @length = 0
    @capacity = 8
    @store = StaticArray.new(@capacity)
  end

  # O(1)
  def [](index)
    check_index_get(index)
    @store[index]
  end

  # O(1)
  def []=(index, value)
    check_index_set(index)
    @store[index] = value
  end

  # O(1)
  def pop
    last_value = self[@length - 1]
    @length -= 1
    last_value
  end

  # O(1) ammortized; O(n) worst case. Variable because of the possible
  def push(val)
    resize! if @length == @capacity
    self[@length] = val
    @length += 1
  end

  # O(n): has to shift over all the elements.
  def shift
    first_value = self[0]
    for index in 1...@length
      self[index - 1] = self[index]
    end
    @length -= 1
    first_value
  end

  # O(n): has to shift over all the elements.
  def unshift(val)
    resize! if @length == @capacity
    (@length - 1).downto(0) do |index|
      self[index + 1] = self[index]
    end
    self[0] = val
    @length += 1
  end

  protected
  def check_index_get(index)
    raise 'index out of bounds' if index >= @length
    raise 'index out of bounds' if index < 0
  end

  def check_index_set(index)
    raise 'index out of bounds' if index > @length
  end

  # O(n): has to copy over all the elements to the new store.
  def resize!
    new_capacity = @capacity * 2
    new_store = StaticArray.new(new_capacity)
    for index in 0...@length
      new_store[index] = self[index]
    end
    @capacity = new_capacity
    @store = new_store
  end
end